CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = philosophers.c utils.c init.c  main.c philosophers_utils.c

OBJS = $(SRCS:.c=.o)

NAME = philo_bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c philosophers.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
