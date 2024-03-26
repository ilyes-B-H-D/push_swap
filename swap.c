/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:55:32 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/26 19:39:56 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_swap(t_stack **stack)
{
	int	temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	temp = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = temp;
}

void	sa(t_stack **a, int print)
{
	ft_swap(a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int print)
{
	ft_swap(b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int print)
{
	ft_swap(a);
	ft_swap(b);
	if (print)
		ft_printf("ss\n");
}
