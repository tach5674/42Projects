CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c r_operations.c ps_operations.c utils.c fill.c list.c sort_5.c sort_bf.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = push_swap

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C libft

$(NAME): $(LIBFT) $(OBJS) push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
