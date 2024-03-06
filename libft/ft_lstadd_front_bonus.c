/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:25:01 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/14 18:22:19 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*=====================testing=======
#include <stdio.h>

int main()
{
    int value1 = 42;
    int value2 = 1337;

    t_list *node1 = (t_list *)malloc(sizeof(t_list));
    t_list *node2 = (t_list *)malloc(sizeof(t_list));

    if (!node1 || !node2)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    node1->content = &value1;
    node1->next = NULL;

    node2->content = &value2;
    node2->next = NULL;

    t_list *list = node1;

    printf("current front : %d \n", *((int *)(list->content)));

    ft_lstadd_front(&list, node2);

    printf("\n");
    printf("after adding a new node : %d \n", *((int *)(list->content)));

    printf("\n");
    return 0;
}
====================================*/