/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:56:17 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/14 22:16:45 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*=====================testing=======
#include <stdio.h>
#include <unistd.h>

int main() {
    char c = 'A';
    int fd = 1; 

    ft_putchar_fd(c, fd);

    return 0;
}
====================================*/