/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:17:04 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/23 18:09:18 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	ft_free(char **res, size_t i, size_t j)
{
	while (j < i)
	{
		free(res[j]);
		j++;
	}
	free(res);
}

static int	ft_word_dup(const char *s, char c, char **res, size_t len)
{
	size_t	i;

	i = 0;
	while (s && *s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			res[i] = ft_substr(s - len, 0, len);
			if (!res[i])
			{
				ft_free(res, i, 0);
				return (0);
			}
			i++;
		}
		else
			s++;
	}
	res[i] = 0;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	res = malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (!res)
		return (NULL);
	if (ft_word_dup(s, c, res, 0) == 0)
		return (NULL);
	return (res);
}
