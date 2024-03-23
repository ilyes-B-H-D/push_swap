
#include "get_next_line.h"
#include <stdlib.h>

int	found_newline(a_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->val[i] && i < BUFFER_SIZE)
		{
			if (list->val[i] == '\n')
				return (1);
			++i;
		}
		printf("%s", list->val);
		list = list->next;
	}
	return (0);
}

a_list	*find_last_node(a_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	copy_str(a_list *list, char *str)
{
	int	i;
	int	k;

	if (NULL == list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->val[i])
		{
			if (list->val[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->val[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

int	len_to_newline(a_list *list)
{
	int	i;
	int	len;

	if (NULL == list)
		return (0);
	len = 0;
	while (list)
	{
		i = 0;
		while (list->val[i])
		{
			if (list->val[i] == '\n')
			{
				++len;
				return (len);
			}
			++i;
			++len;
		}
		list = list->next;
	}	
	return (len);
}

void	dealloc(a_list **list, a_list *clean_node, char *buf)
{	
	a_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->val);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->val[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
