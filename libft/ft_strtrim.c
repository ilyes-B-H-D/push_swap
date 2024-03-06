/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:18:32 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/14 18:59:45 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	return (str);
}
/*=====================testing=======
#include <stdio.h>

int main()
{
    const char *input = "   Hello, world!   ";
    const char *set = " ";

    char *result = ft_strtrim(input, set);

    if (result != NULL)
    {
        printf("Original string: \"%s\"\n", input);
        printf("Trimmed string: \"%s\"\n", result);
    }
    else
        printf("Memory allocation failed.\n");
    return 0;
}
====================================*/
