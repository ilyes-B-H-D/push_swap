/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:29:56 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/23 18:09:34 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s, const char *p, size_t n)
{
	while (*s != '\0' && *(unsigned char *)s == *(unsigned char *)p && n > 0)
	{
		s++;
		p++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s - *(unsigned char *)p);
}
