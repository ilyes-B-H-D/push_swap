#include "./push_swap.h"

int	ft_error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (1);
	while (*++str)
		if (!ft_isdigit(*str))
			return (1);
	return (0);
}

int	ft_error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a->value != n && a->next)
		a = a->next;
    if (a->value == n)
        return (1);
	return (0);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
