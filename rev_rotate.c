/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benhajdahmaneilyes <benhajdahmaneilyes@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:09:32 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/16 18:30:36 by benhajdahma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*current;

	if (!(*stack) || !(*stack)->next)
		return ;
	prev = NULL;
	current = *stack;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}

void	rra(t_stack **a)
{
	ft_rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	ft_rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	ft_printf("rrr\n");
}