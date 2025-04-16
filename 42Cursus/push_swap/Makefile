CC = cc
CFLAGS = -Wall -Wextra -Werror -I INCLUDES

SRC_FOLDER = SRCS
OBJ_FOLDER = SRCS
BONUS_SRC_FOLDER = BONUS
BONUS_OBJ_FOLDER = BONUS

SRCS = $(SRC_FOLDER)/push_swap.c \
       $(SRC_FOLDER)/r_operations.c \
       $(SRC_FOLDER)/ps_operations.c \
       $(SRC_FOLDER)/utils.c \
       $(SRC_FOLDER)/fill.c \
       $(SRC_FOLDER)/list.c \
       $(SRC_FOLDER)/sort_5.c \
       $(SRC_FOLDER)/sort_bf.c

BONUS_SRCS = $(BONUS_SRC_FOLDER)/checker.c \
			$(BONUS_SRC_FOLDER)/r_operations.c \
			$(BONUS_SRC_FOLDER)/ps_operations.c \
			$(BONUS_SRC_FOLDER)/utils.c \
			$(BONUS_SRC_FOLDER)/list.c \
			$(BONUS_SRC_FOLDER)/sort.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = push_swap

BONUS_NAME = checker

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -Llibft -lft -o $(BONUS_NAME)

%.o: %.c INCLUDES/*
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
