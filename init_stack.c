/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:35:19 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/23 18:21:36 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->val = n;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = ft_find_last(*stack);
		last_node->next = node;
	}
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)

{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_med)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_med)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

int	ft_search(char *av, char *c)
{
	int	i;

	i = 0;
	while (*av)
	{
		while (c[i])
		{
			if (*av == c[i])
				return (1);
			i++;
		}
		i = 0;
		av++;
	}
	return (0);
}

void	ft_handle(t_stack **a, char *arg)
{
	char	**newrs;
	int		i;
	int		n;

	i = 0;
	if (ft_search(arg, " "))
	{
		newrs = ft_split(arg, ' ');
		while (newrs[i])
		{
			ft_handle(a, newrs[i]);
			i++;
		}
	}
	else
	{
		n = ft_atol(arg);
		if (n > INT_MAX || n < INT_MIN || ft_error_duplicate(*a, (int)n))
		{
			ft_free_stack(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		append_node(a, (int)n);
	}
}

void	ft_init_stack(t_stack **a, char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_search(av[i], "0123456789"))
		{
			ft_free_stack(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		ft_handle(a, av[i]);
		i++;
	}
}
