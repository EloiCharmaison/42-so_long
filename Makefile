NAME = so_long.a

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
		src/flood.c \
		src/input.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf.a
LIBFT_DIR = $(PRINTF_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	make -C $(MLX_DIR)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all
