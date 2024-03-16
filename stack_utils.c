/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benhajdahmaneilyes <benhajdahmaneilyes@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:13:57 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/16 18:30:36 by benhajdahma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

 t_stack    *ft_find_last(t_stack *stack)
 {
     t_stack *last;

     last = stack;
     while (last->next)
         last = last->next;
     return (last);
 }
 t_stack    *ft_find_min(t_stack *stack) 
 {
     t_stack *min;

     min = stack;
     while (stack)
     {
         if (stack->value < min->value)
             min = stack;
         stack = stack->next;
     }
     return (min);
 }


 t_stack    *ft_find_max(t_stack *stack) 
 {
     t_stack *max;

     max = stack;
     while (stack)
     {
         if (stack->value > max->value)
             max = stack;
         stack = stack->next;
     }
     return (max);
 }

 bool	ft_stack_sorted(t_stack *stack)
{
	while (stack && stack->next) 
	{
		if (stack->value > stack->next->value) 
			return (false);
		stack = stack->next;
	}
	return (true);
}
