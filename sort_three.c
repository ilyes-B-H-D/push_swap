#include "./push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int a = (*stack)->val;
	int b = (*stack)->next->val;
	int c = (*stack)->next->next->val;

	if (a > b && a < c)
		sa(&(*stack));
	else if (a > b && a > c)
	{
		ra(stack);
		if ((*stack)->val > (*stack)->next->val)
			sa(stack);
	}
	else if (b > a && b > c)
	{
		rra(stack);
		if ((*stack)->val > (*stack)->next->val)
			sa(stack);
	}
}