/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:03:43 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/26 19:42:06 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->val;
	b = (*stack)->next->val;
	c = (*stack)->next->next->val;
	if (a > b && a < c)
		sa(&(*stack), 1);
	else if (a > b && a > c)
	{
		ra(stack, 1);
		if ((*stack)->val > (*stack)->next->val)
			sa(stack, 1);
	}
	else if (b > a && b > c)
	{
		rra(stack, 1);
		if ((*stack)->val > (*stack)->next->val)
			sa(stack, 1);
	}
}
