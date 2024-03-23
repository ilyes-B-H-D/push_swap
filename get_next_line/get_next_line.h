#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct k_list
{
	char			*val;
	struct k_list	*next;
}					a_list;

int					found_newline(a_list *list);
a_list				*find_last_node(a_list *list);
char				*get_line(a_list *list);
void				copy_str(a_list *list, char *str);
int					len_to_newline(a_list *list);
void				save_list(a_list **list);
char				*get_next_line(int fd);
void				dealloc(a_list **list, a_list *clean_node, char *buf);
void				create_list(a_list **list, int fd);

#endif
