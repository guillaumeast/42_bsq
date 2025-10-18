NAME := bsq

CC     	:= cc
CFLAGS 	:= -Wall -Wextra -Werror

SRC_DIR	:= srcs
INC_DIR	:= includes
OBJ_DIR	:= obj

SRCS 	:= $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJS	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS 	:= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

-include $(DEPS)

debug: CFLAGS += -g3
debug: re

clean:
	rm -r $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re:		fclean all

.PHONY: all debug clean fclean re