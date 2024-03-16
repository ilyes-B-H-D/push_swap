#include "./push_swap.h"


void	ft_init_nodes_b(t_stack* a, t_stack* b)
{
	t_stack* current_a;
	t_stack* target_node;
	long			best_match_index;

	ft_current_index(a);
	ft_current_index(b);
	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = ft_find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
