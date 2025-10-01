NAME := bsq

CC     := cc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := srcs
INCDIR	:= includes

SRCS :=	$(wildcard $(SRC_DIR)/*.c) \
		$(wildcard $(SRC_DIR)/*/*.c)
OBJS := $(SRCS:.c=.o)
DEPS := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -MMD -MP -c $< -o $@

-include $(DEPS)

debug: CFLAGS += -g3
debug: re

sanitize: CFLAGS += -fsanitize=address
sanitize: re

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all debug clean fclean re