CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c utils.c get_path.c pipex_split.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = pipex_bonus.c utils_bonus.c get_path_bonus.c pipex_split_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = pipex

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS) pipex.h
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJS) pipex_bonus.h
	$(CC) $(CFLAGS) $(BONUS_OBJS) -Llibft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re $(NAME) bonus
