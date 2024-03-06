/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benhajdahmaneilyes <benhajdahmaneilyes@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:09:32 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/06 11:41:43 by benhajdahma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void ft_rev_rotate(t_stack** stack) 
{
    if (!(*stack) || !(*stack)->next) 
        return;

    t_stack *prev = NULL;
    t_stack *current = *stack;

    while (current->next) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    current->next = *stack;
    *stack = current;
}   

void	rra(t_stack **a, bool print) 
{
	ft_rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print) 
{
	ft_rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}