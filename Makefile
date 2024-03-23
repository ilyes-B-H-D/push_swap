NAME = push_swap
NAME_B = checker

SRC =	./push.c \
		./rotate.c \
		./rev_rotate.c \
		./sort_three.c \
		./swap.c \
		./handle_errors.c \
		./init_stack.c \
		./push_swap.c \
		./sort_stacks.c \
		./stack_utils.c \
		./push_a_to_b.c \
		./push_b_to_a.c

SRC_B =	$(SRC) \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./checker.c
		
OBJ = $(SRC:.c=.o)
BOBJ = $(SRC_B:.c=.o)

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
bonus: $(NAME_B)

$(NAME): $(OBJ)
	@make -C libft
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(NAME_B): $(BOBJ)
	@make -C libft
	@make -C ft_printf
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) $(PRINTF) -o $(NAME_B)

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@rm -rf $(OBJ) $(BOBJ)

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -rf $(NAME) $(NAME_B)

re: fclean all

.PHONY: all bonus clean fclean re
