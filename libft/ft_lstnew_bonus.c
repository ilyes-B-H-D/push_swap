/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:44:02 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/14 18:22:19 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*e;

	e = (t_list *)malloc(sizeof(*e));
	if (!e)
		return (NULL);
	e->content = content;
	e->next = NULL;
	return (e);
}
/*=====================testing=======
#include <stdio.h>

int main()
{
    int value = 1337;

    t_list *newNode = ft_lstnew(&value);

    if (newNode != NULL)
        printf("New node content: %d\n", *((int *)(newNode->content)));
    else
        printf("Memory allocation failed.\n");

    return 0;
}
====================================*/