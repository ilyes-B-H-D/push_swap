/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:52:44 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/18 19:30:43 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!b && l) && len == 0)
		return (0);
	if (l[0] == '\0')
		return ((char *)b);
	while (b[i] && i < len)
	{
		j = 0;
		while (b[i + j] == l[j] && b[i + j] && l[j] && (i + j) < len)
			j++;
		if (l[j] == '\0')
			return ((char *)&b[i]);
		i++;
	}
	return (NULL);
}