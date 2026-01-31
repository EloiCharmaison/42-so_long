NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = src
OBJS = obj

MLX = -lmlx -lXext -lX11 -lm -lz -lpthread

SRCS =	src/main.c \
		src/read_map.c \
		src/map_checker.c \
		src/render.c \
		src/mlx_init_game.c \
		src/close_game.c \
		src/player.c \
		src/input.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
