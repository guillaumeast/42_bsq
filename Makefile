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

fast: CFLAGS += -O3 -DNDEBUG -march=native -flto
fast: LDFLAGS += -flto
fast: re

sfast: CFLAGS += -O3 -ffast-math -DNDEBUG -march=native -flto
sfast: LDFLAGS += -flto
sfast: re

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all debug profile fast sfast clean fclean re