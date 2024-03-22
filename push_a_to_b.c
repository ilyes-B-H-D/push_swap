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
		stack->index = i;
		if (i <= median)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target(t_stack *a, t_stack *b)
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
			a->target = ft_find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	cost_analysis(t_stack *a, t_stack *b)
{
	int	lena;
	int	lenb;

	lena = ft_stack_len(a);
	lenb = ft_stack_len(b);
	while (a)
	{
		if (a->above_med && a->target->above_med)
			a->push_cost = a->index + abs(a->index - a->target->index);
		else if (!a->above_med && !a->target->above_med)
		{
			// printf("========> this is the val %d and this is the target
				// %d\n",
			// 	a->val, a->target->val);
			a->push_cost = lena - a->index + abs(lena - a->index - (lenb
						- a->target->index));
			// printf("push cost %d\n", abs(lena - a->index - (lenb
			// - a->target->index)));
		}
		else
		{
			a->push_cost = a->index;
			if (!(a->above_med))
				a->push_cost = lena - (a->index);
			if (a->target->above_med)
				a->push_cost += a->target->index;
			else
				a->push_cost += lenb - (a->target->index);
		}
		// printf("val %d : index %d | target val %d : index %d | cost %d\n ",
		// 	a->val, a->index, a->target->val, a->target->index, a->push_cost);
		// a->push_cost = a->index;
		// if (!(a->above_med))
		// 	a->push_cost = lena - (a->index);
		// if (a->target->above_med)
		// 	a->push_cost += a->target->index;
		// else
		// 	a->push_cost += lenb - (a->target->index);
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
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	ft_init_nodes(t_stack *a, t_stack *b)
{
	ft_current_index(a);
	ft_current_index(b);
	set_target(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}