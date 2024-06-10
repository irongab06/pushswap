NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = algo_sort.c check_argv.c ft_lst.c \
main.c push_swap.c push_swap_utile.c \

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re bonus
