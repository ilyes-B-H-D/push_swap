#include "./push_swap.h"

void	ft_init_nodes_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_match_index;

	ft_current_index(a);
	ft_current_index(b);
	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->val > b->val
				&& current_a->val < best_match_index)
			{
				best_match_index = current_a->val;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = ft_find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}
