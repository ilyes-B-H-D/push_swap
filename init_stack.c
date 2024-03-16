#include "./push_swap.h"

long ft_atol(const char* s)
{
	long res;
	int sign;

	res = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * sign);
}

static void append_node(t_stack** stack, int n)
{
	t_stack* node;
	t_stack* last_node;

	if (!stack)
		return;
	node = malloc(sizeof(t_stack));
	if (!node)
		return;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void ft_init_stack_a(t_stack** a, char** av)
{
	long n;
	int i;

	i = 0;
	while (av[i])
	{
		if (ft_error_syntax(av[i]))
		{
			ft_free_stack(a);
			ft_printf("Error\n");
			exit(1);
		}
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN || ft_error_duplicate(*a, (int)n))
		{
			ft_free_stack(a);
			ft_printf("Error\n");
			exit(1);
		}
		append_node(a, (int)n);
		i++;
	}
}

t_stack* ft_get_cheapest(t_stack* stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void ft_prep_for_push(t_stack** stack,
	t_stack* top_node,
	char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}