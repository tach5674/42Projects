CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
INCLUDE_DIR = includes

SRCS = $(SRC_DIR)/ft_putchar.c \
	   $(SRC_DIR)/ft_putstr.c \
	   $(SRC_DIR)/ft_strcmp.c \
	   $(SRC_DIR)/ft_strlen.c \
	   $(SRC_DIR)/ft_swap.c

OBJS = $(SRCS:.c=.o)

LIBRARY = libft.a

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	ar rcs $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBRARY)

re: fclean all

.PHONY: all clean fclean re
