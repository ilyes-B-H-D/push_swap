/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:04:01 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/23 18:21:10 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->idx = i;
		if (i <= median)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->val < a->val && current_b->val > best_match)
			{
				best_match = current_b->val;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->trg = ft_find_max(b);
		else
			a->trg = target;
		a = a->next;
	}
}

void	cost(t_stack *a, t_stack *b)
{
	int	lena;
	int	lenb;

	ft_current_index(a);
	ft_current_index(b);
	lena = ft_stack_len(a);
	lenb = ft_stack_len(b);
	while (a)
	{
		if (a->above_med && a->trg->above_med)
			a->cost = a->idx + abs(a->idx - a->trg->idx);
		else if (!a->above_med && !a->trg->above_med)
			a->cost = lena - a->idx + abs(lena - a->idx - (lenb - a->trg->idx));
		else
		{
			a->cost = a->idx;
			if (!(a->above_med))
				a->cost = lena - (a->idx);
			if (a->trg->above_med)
				a->cost += a->trg->idx;
			else
				a->cost += lenb - (a->trg->idx);
		}
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
