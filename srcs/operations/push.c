/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benhajdahmaneilyes <benhajdahmaneilyes@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:09:25 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/03 15:46:15 by benhajdahma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void ft_push(t_stack **dst, t_stack **src)
{
	t_stack *push_node;

	if (!*src)
		return;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void pa(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_printf("pa\n");
}

void pb(t_stack **b, t_stack **a)
{
	ft_push(b, a);
	ft_printf("pb\n");
}