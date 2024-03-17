# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 13:56:28 by iben-haj          #+#    #+#              #
#    Updated: 2024/03/17 00:08:56 by iben-haj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

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
		./parse.c \
		./push_a_to_b.c \
		./push_b_to_a.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re