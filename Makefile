# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: benhajdahmaneilyes <benhajdahmaneilyes@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 13:56:28 by iben-haj          #+#    #+#              #
#    Updated: 2024/03/06 12:59:38 by benhajdahma      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	./srcs/operations/push.c \
		./srcs/operations/rotate.c \
		./srcs/operations/rev_rotate.c \
		./srcs/operations/sort_three.c \
		./srcs/operations/swap.c \
		./srcs/push_swap/handle_errors.c \
		./srcs/push_swap/init_stack.c \
		./srcs/push_swap/push_swap.c \
		./srcs/push_swap/sort_stacks.c \
		./srcs/push_swap/stack_utils.c \
		./srcs/push_swap/split.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft
	@make -C ft_printf
	@$(CC) $(FLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)

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