/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:17:16 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/29 15:42:10 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 && res > (INT_MAX - (str[i] - '0')) / 10)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		else if (sign == -1 && - (res) < (INT_MIN + (str[i] - '0')) / 10)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	if (str[i] != '\0')
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
