/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:11:00 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/14 20:22:58 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*=====================testing=======
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

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    int size = ft_lstsize(node1);

    printf("Size of the linked list: %d\n", size);
    return 0;
}
====================================*/