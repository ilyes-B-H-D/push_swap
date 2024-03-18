#include "./push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int a = (*stack)->value;
	int b = (*stack)->next->value;
	int c = (*stack)->next->next->value;

	if (a > b && a < c)
		sa(&(*stack));
	else if (a > b && a > c)
	{
		ra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
	else if (b > a && b > c)
	{
		rra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}


	
}