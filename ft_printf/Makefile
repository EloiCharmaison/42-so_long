NAME = ft_printf.a

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = src/ft_print_chr.c  src/ft_print_hex.c src/ft_print_hexmaj.c src/ft_print_nbr.c src/ft_print_ptr.c src/ft_print_str.c src/ft_print_unsigned.c src/ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
		cp $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJS)

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)
		make clean -C $(LIBFT_DIR)

fclean: clean
		rm -f $(NAME)
		make fclean -C$(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re