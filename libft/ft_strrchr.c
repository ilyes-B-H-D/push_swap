/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:36:36 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/23 18:09:51 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			t = ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		t = ((char *)&str[i]);
	return (t);
}
