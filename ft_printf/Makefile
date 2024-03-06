# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 15:06:23 by iben-haj          #+#    #+#              #
#    Updated: 2023/11/19 15:06:24 by iben-haj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c srcs/ft_putaddr.c srcs/ft_putchar.c srcs/ft_puthexa.c srcs/ft_putnbr.c srcs/ft_putstr.c srcs/ft_putunbr.c srcs/ft_check.c 

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ}

fclean:
	rm -rf ${NAME} ${OBJ}

re: fclean all

.PHONY: fclean all  clean re