CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_c.c ft_printf_s.c ft_printf_p.c ft_printf_di.c ft_printf_ux.c ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = libftprintf.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME) 
	ar rcs $@ $^

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
