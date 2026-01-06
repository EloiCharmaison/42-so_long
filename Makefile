NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
OGJ_DIR = obj
INC_DIR = include

MLX = -lmlx -lXext -lX11 -lm -lz -lpthread

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/map.c \
		$(SRC_DIR)/game.c \
		$(SRC_DIR)/render.c \
		$(SRC_DIR)/utils.c

OBJ = $(patsubst $(	SRC_DIR)/%.c,$(OBJ_DIR)/%.o$(SRC))
