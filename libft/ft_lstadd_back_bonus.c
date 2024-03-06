/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:24:10 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/18 19:08:28 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new && !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}
/*==============testing================
#include <stdio.h>

int main()
{
    t_list *node1 = (t_list *)malloc(sizeof(t_list));
    t_list *node2 = (t_list *)malloc(sizeof(t_list));
    t_list *node3 = (t_list *)malloc(sizeof(t_list));

    if (!node1 || !node2 || !node3)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    node1->content = "Node 1 data";
    node1->next = NULL;

    node2->content = "Node 2 data";
    node2->next = NULL;

    node3->content = "Node 3 data";
    node3->next = NULL;

    t_list *list = node1;

    printf("Original list:\n");
    while (list)
    {
        printf("%s ", (char *)(list->content));
        list = list->next;
    }
    printf("\n");

    t_list *newNode = (t_list *)malloc(sizeof(t_list));
    newNode->content = "New Node data";
    newNode->next = NULL;

    ft_lstadd_back(&list, newNode);

    printf("List after adding a new node at the back:\n");
    list = node1; 
    while (list)
    {
        printf("%s ", (char *)(list->content));
        list = list->next;
    }
    printf("\n");
    return 0;
}
=======================================*/