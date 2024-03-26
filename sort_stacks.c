/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:35:02 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/26 19:43:00 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_med && cheapest->trg->above_med)
		while (*b != cheapest->trg && *a != cheapest)
			rr(a, b, 1);
	else if (!(cheapest->above_med) && !(cheapest->trg->above_med))
		while (*b != cheapest->trg && *a != cheapest)
			rrr(a, b, 1);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->trg, 'b');
	pb(b, a, 1);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_stack_len(*a);
	if (len-- > 3 && !ft_stack_sorted(*a))
		pb(b, a, 1);
	if (len-- > 3 && !ft_stack_sorted(*a))
		pb(b, a, 1);
	while (len-- > 3 && !ft_stack_sorted(*a))
	{
		set_target(*a, *b);
		cost(*a, *b);
		set_cheapest(*a);
		move_to_b(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_b(*a, *b);
		prep_for_push(a, (*b)->trg, 'a');
		pa(a, b, 1);
	}
	ft_current_index(*a);
	while ((*a)->val != ft_find_min(*a)->val)
	{
		if (ft_find_min(*a)->above_med)
			ra(a, 1);
		else
			rra(a, 1);
		ft_current_index(*a);
	}
}
