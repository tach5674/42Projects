CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iincludes -Imlx_linux

SRC_FOLDER = srcs
OBJ_FOLDER = srcs

SRCS = $(SRC_FOLDER)/fdf.c \
		$(SRC_FOLDER)/color_encoder_decoder.c \
		$(SRC_FOLDER)/color_management.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = fdf

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -O3 -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
