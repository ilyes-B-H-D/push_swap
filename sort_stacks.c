/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:35:02 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/20 11:02:15 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = ft_get_cheapest(*a);
	// printf("this is the cheapest %d || target value %d\n", cheapest->val, cheapest->target->val);
	if (cheapest->above_med && cheapest->target->above_med)
		while (*b != cheapest->target && *a != cheapest)
			rr(a, b);
	else if (!(cheapest->above_med) && !(cheapest->target->above_med))
		while (*b != cheapest->target && *a != cheapest)
			rrr(a, b);
	ft_prep_for_push(a, cheapest, 'a');
	ft_prep_for_push(b, cheapest->target, 'b');
	pb(b, a);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_stack_len(*a);
	if (len-- > 3 && !ft_stack_sorted(*a))
		pb(b, a);
	if (len-- > 3 && !ft_stack_sorted(*a))
		pb(b, a);
	while (len-- > 3 && !ft_stack_sorted(*a))
	{
		ft_init_nodes(*a, *b);
		move_a_to_b(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_nodes_b(*a, *b);
		ft_prep_for_push(a, (*b)->target, 'a');
		pa(a, b);
	}
	ft_current_index(*a);
	while ((*a)->val != ft_find_min(*a)->val)
	{
		if (ft_find_min(*a)->above_med)
			ra(a);
		else
			rra(a);
		ft_current_index(*a);
	}
}
