/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:55:15 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/23 18:13:20 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack = (*stack)->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
