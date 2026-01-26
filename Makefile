NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = src
OBJS = obj

MLX = -lmlx -lXext -lX11 -lm -lz -lpthread

SRCS =	src/main.c \
		src/read_map.c \
		src/map_checker.c \
		src/game.c \
		src/render.c \
		src/utils.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
