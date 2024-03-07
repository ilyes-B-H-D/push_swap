#include "../../push_swap.h"

static void rotate_both(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
	ft_current_index(*a);
	ft_current_index(*b);
}

static void rev_rotate_both(t_stack **a,
							t_stack **b,
							t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	ft_current_index(*a);
	ft_current_index(*b);
}

static void move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;

	cheapest_node = ft_get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	ft_prep_for_push(a, cheapest_node, 'a');
	ft_prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

static void move_b_to_a(t_stack **a, t_stack **b)
{
	ft_prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void min_on_top(t_stack **a)
{
	while ((*a)->value != ft_find_min(*a)->value)
	{
		if (ft_find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void sort_stacks(t_stack **a, t_stack **b)
{
	int len_a;

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
	ft_sort_three(*a);
	while (*b)
	{
		ft_init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	ft_current_index(*a);
	min_on_top(a);
}
