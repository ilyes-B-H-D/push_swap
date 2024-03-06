/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:42:20 by iben-haj          #+#    #+#             */
/*   Updated: 2023/11/16 23:32:03 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;	
	void	*val;

	if (!f || !del || !lst)
		return (NULL);
	new = NULL;
	head = new;
	while (lst)
	{
		val = (*f)(lst->content);
		new = ft_lstnew(val);
		if (!new)
		{
			ft_lstclear(&head, del);
			free(val);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
