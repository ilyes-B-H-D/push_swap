
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>//TODO


void	save_list(a_list **list)
{
	a_list	*last_node;
	a_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(a_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->val[i] && last_node->val[i] != '\n')
		++i;
	while (last_node->val[i] && last_node->val[++i])
		buf[k++] = last_node->val[i];
	buf[k] = '\0';
	clean_node->val = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
}


char	*get_line(a_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}


void	append(a_list **list, char *buf)
{
	a_list	*new_node;
	a_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(a_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->val = buf;
	new_node->next = NULL;
}

void	create_list(a_list **list, int fd)
{
	int		bytes_read;	
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buf);
			return ;
		}
		buf[bytes_read] = '\0';
		append(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static a_list	*list = NULL;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	save_list(&list);
	return (next_line);
}

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>

int main ()
{
    int fd = open("file.txt", O_RDWR);
    char *s;
    s = get_next_line(fd);
    while(s)
    {
        printf("%s", s);
        s = get_next_line(fd);
    }
    return (0);
}