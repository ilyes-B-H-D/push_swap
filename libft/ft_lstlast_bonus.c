/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:13:40 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/16 18:27:57 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*=====================testing=======
#include <stdio.h>

int main()
{
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	t_list *node3 = (t_list *)malloc(sizeof(t_list));

	int v1 = 1;
	int v2 = 2;
	int v3 = 3;
	
	if (!node1 || !node2 || !node3)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	node1->content = &v1;
	node2->content = &v2;
	node3->content = &v3;
	
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	t_list *lastNode = ft_lstlast(node1);

	if (lastNode)
		printf("Content of the last node: %d\n", *((int *)(lastNode->content)));
	else
		printf("The list is empty.\n");
	return 0;
}
====================================*/