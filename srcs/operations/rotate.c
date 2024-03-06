/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benhajdahmaneilyes <benhajdahmaneilyes@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:55:15 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/06 11:41:15 by benhajdahma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void ft_rotate(t_stack** stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_stack* first = *stack;
    t_stack* last = *stack;

    while (last->next != NULL) {
        last = last->next;
    }
    
    *stack = (*stack)->next;
    first->next = NULL;

    last->next = first;
}

void	ra(t_stack **a, bool print) 
{
	ft_rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool print) 
{
	ft_rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool print) 
{
	ft_rotate(a);
	ft_rotate(b);
	if (!print)
		ft_printf("rr\n");
}