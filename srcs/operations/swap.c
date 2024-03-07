/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benhajdahmaneilyes <benhajdahmaneilyes@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:55:32 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/06 11:44:54 by benhajdahma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void ft_swap(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next)
		return;

	int temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void sa(t_stack **a)
{
	ft_swap(a);
	ft_printf("sa\n");
}

void sb(t_stack **b)
{
	ft_swap(b);
	ft_printf("sb\n");
}

void ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}