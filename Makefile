NAME := bsq

CC     	:= cc
CFLAGS 	:= -Wall -Wextra -Werror
LDFLAGS	:=

SRC_DIR	:= srcs
INC_DIR	:= includes
OBJ_DIR	:= obj

SRCS 	:= $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJS	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS 	:= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

-include $(DEPS)

debug: CFLAGS += -g3
debug: re

profile: CFLAGS += -O3 -g -fno-omit-frame-pointer -march=native
profile: re

fast: CFLAGS += -O3 -DNDEBUG -march=native -flto -fomit-frame-pointer -fno-stack-protector
fast: LDFLAGS += -flto
fast: re

bench:
	@sudo caffeinate nice -n -20 ./bsq --bench tests/test_10000 > /dev/null

# ---------------------------------------------------------
# 🔥 Profile-Guided Optimization (PGO - Clang/LLVM)
# ---------------------------------------------------------
PGO_FLAGS	= -O3 -DNDEBUG -march=native -flto -fomit-frame-pointer -fno-stack-protector
PGO_INPUTS	= tests/basic_test tests/test_2000 tests/test_5000 tests/test_10000
PGO_DIR		= pgo_obj

sfast:
	@echo "\n🧮 [1/4] Building instrumented binary..."
	@$(MAKE) -s fclean >/dev/null
	@mkdir -p $(PGO_DIR)
	@$(MAKE) -s CFLAGS="$(PGO_FLAGS) -fprofile-instr-generate=$(PGO_DIR)/bsq-%p-%m.profraw" >/dev/null

	@echo "\n⚙️  [2/4] Running program to collect profiles..."
	@for f in $(PGO_INPUTS); do \
		echo "   → $$f"; \
		LLVM_PROFILE_FILE="$(PGO_DIR)/bsq-%p-%m.profraw" ./$(NAME) "$$f" > /dev/null 2>&1 || exit 1; \
	done

	@echo "\n👨‍🍳 [3/4] Merging profiles"
	@xcrun llvm-profdata merge -o $(PGO_DIR)/default.profdata $(PGO_DIR)/bsq-*.profraw

	@echo "\n🚀 [4/4] Rebuilding with PGO optimizations"
	@$(MAKE) -s fclean >/dev/null
	@$(MAKE) CFLAGS="$(PGO_FLAGS) -fprofile-instr-use=$(PGO_DIR)/default.profdata" >/dev/null
	@ rm -r $(PGO_DIR)

	@echo "\n✅ PGO build complete! Binary optimized using real runtime data."

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all debug profile fast sfast clean fclean re