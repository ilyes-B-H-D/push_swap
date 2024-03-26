/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:35:09 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/26 19:41:27 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include "push_swap.h"

int	execute(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(line, "sa", 2))
		sa(stack_a, 0);
	else if (!ft_strncmp(line, "sb", 2))
		sb(stack_b, 0);
	else if (!ft_strncmp(line, "ss", 2))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "pa", 2))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "pb", 2))
		pb(stack_b, stack_a, 0);
	else if (!ft_strncmp(line, "ra", 2))
		ra(stack_a, 0);
	else if (!ft_strncmp(line, "rb", 2))
		rb(stack_b, 0);
	else if (!ft_strncmp(line, "rr", 2))
		rr(stack_a, stack_a, 0);
	else if (!ft_strncmp(line, "rra", 2))
		rra(stack_a, 0);
	else if (!ft_strncmp(line, "rrb", 2))
		rrb(stack_b, 0);
	else if (!ft_strncmp(line, "rrr", 2))
		rrr(stack_a, stack_b, 0);
	else
		return (1);
	return (0);
}

void	print_checker_res(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_len(*stack_b) > 0)
		ft_putendl_fd("KO", 1);
	else if (ft_stack_sorted(*stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	if (*stack_a)
		ft_free_stack(stack_a);
	if (*stack_b)
		ft_free_stack(stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	line = get_next_line(0);
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	ft_init_stack(&a, av + 1);
	while (line)
	{
		if (execute(line, &a, &b))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		free(line);
		line = get_next_line(0);
	}
	print_checker_res(&a, &b);
	return (0);
}
