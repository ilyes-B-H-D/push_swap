/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:35:09 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/29 15:49:13 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include "push_swap.h"

int	execute(char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(stack_b, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(stack_b, stack_a, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(stack_b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
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

ft_check(int ac, char **av)
{
	if (ac == 1)
		return (1);
	else if (ac == 2 && !av[1][0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	ft_check(ac, av);
	ft_init_stack(&a, av + 1);
	line = get_next_line(0);
	while (line)
	{
		if (execute(line, &a, &b))
		{
			ft_free_stack(&a);
			ft_free_stack(&b);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
	print_checker_res(&a, &b);
	return (0);
}
