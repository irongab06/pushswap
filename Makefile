NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = src/main.c src/push.c src/rotate.c\
src/rr_rrr_ss.c src/sort_for_2.c src/sort_for_3.c\
src/sort_for_5.c src/swap.c\
src/sort_nolimit_part1.c src/sort_nolimit_part2.c\
utile/check_argv.c utile/ft_lst.c\
utile/push_swap_utile_1.c utile/push_swap_utile_2.c\
utile/push_swap_utile.c

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
