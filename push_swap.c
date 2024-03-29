/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:04:09 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/29 15:48:21 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

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

	a = NULL;
	b = NULL;
	ft_check(ac, av);
	ft_init_stack(&a, av + 1);
	if (!ft_stack_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, 1);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	if (a)
		ft_free_stack(&a);
	if (b)
		ft_free_stack(&b);
	return (0);
}
