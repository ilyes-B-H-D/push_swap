/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:02:03 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/16 18:18:08 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > 0xffffffff / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*=====================testing=======
#include <stdio.h>

int main()
{
    char *p = calloc(0xffffffff ,0xffffffff);
    char *p2 = ft_calloc(0xffffffff, 0xffffffff);

    if (p) printft("done"); else printft("error"); 
    if (p2) printft("done"); else printft("error"); 
}
====================================*/