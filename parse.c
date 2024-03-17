#include "./push_swap.h"

static int	count_words(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == ' ')
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != ' ')
				i++;
		}
	}
	return (count);
}

static char	*get_next_word(char *s)
{
	static int	i = 0;
	char		*res;
	int			j;
	int			k;

	j = 0;
	k = 0;
	while (s[i] == ' ')
		i++;
	while ((s[i + j] != ' ') && s[i + j])
		j++;
	res = malloc((size_t)j * sizeof(char) + 1);
	if (!res)
		return (NULL);
	while ((s[i] != ' ') && s[i])
		res[k++] = s[i++];
	res[k] = '\0';
	return (res);
}

char	**parse(char *s)
{
	int		words_count;
	char	**res;
	int		i;

	i = 0;
	words_count = count_words(s);
	if (!words_count)
		exit(1);
	res = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!res)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			res[i] = malloc(sizeof(char));
			if (!res[i])
				return (NULL);
			res[i++][0] = '\0';
			continue ;
		}
		res[i++] = get_next_word(s);
	}
	res[i] = NULL;
	return (res);
}
