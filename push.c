/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:09:25 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/16 23:42:59 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (!*dst)
	{
		*dst = push_node;
		(*dst)->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		*dst = push_node;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	ft_push(b, a);
	ft_printf("pb\n");
}