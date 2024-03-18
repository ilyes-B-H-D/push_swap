/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:35:02 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/18 01:10:43 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rr(a, b);
		ft_current_index(*a);
		ft_current_index(*b);
	}
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rrr(a, b);
		ft_current_index(*a);
		ft_current_index(*b);
	}
	ft_prep_for_push(a, cheapest_node, 'a');
	ft_prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_stack_len(*a);
	if (len_a-- > 3 && !ft_stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !ft_stack_sorted(*a))
		pb(b, a);


	while (len_a-- > 3 && !ft_stack_sorted(*a))
	{
		ft_init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}

	if (!ft_stack_sorted(*a))
		ft_sort_three(a);

	// t_stack *tmp = *a;
	// while((tmp))
	// {
	// 	printf("%d\n", (tmp)->value);
	// 	(tmp) = (tmp)->next;
	// }
	
	
	while (*b)
	{
		ft_init_nodes_b(*a, *b);
		ft_prep_for_push(a, (*b)->target_node, 'a');
		pa(a, b);
	}
	ft_current_index(*a);
	
	// t_stack *tmp = *a;
	// while((tmp))
	// {
	// 	printf("%d\n", (tmp)->value);
	// 	(tmp) = (tmp)->next;
	// }
	// int i = 0;////////////
				// printf("len ==> %d\n", ft_stack_len(*a));

	
	while ( (*a)->value != ft_find_min(*a)->value)
	{
		if (ft_find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
		ft_current_index(*a);
		// (*a) = (*a)->next;
			
			// while((tmp))
			// {
				// printf("len ==> %d\n", ft_stack_len(*a));
			// 	(tmp) = (tmp)->next;
			// }
	// 		i++;
	}
	
}
