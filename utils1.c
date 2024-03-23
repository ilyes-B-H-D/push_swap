/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:17:16 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/23 18:37:29 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

long	ft_atol(const char *s)
{
	long	res;
	int		sign;
	int		check;

	check = 0;
	res = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
		check = 1;
	}
	if (!check)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (res * sign);
}

t_stack	*get_cheapest(t_stack *stack)
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
