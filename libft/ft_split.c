/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benhajdahmaneilyes <benhajdahmaneilyes@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:17:04 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/06 12:53:13 by benhajdahma      ###   ########.fr       */
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
/*=====================testing=======
#include <stdio.h>

int main(int argc, char **av) {
(void)argc;
const char *input = av[1];
char delimiter = av[2][0];

char **words = ft_split(input, delimiter);

if (words) {
	int i = 0;
	while (words[i]) 
	{
		printf("Word %d: %s\n", i + 1, words[i]);
		i++;
	}
} 
else 
	printf("Memory allocation failed.\n");

return 0;
}
====================================*/
