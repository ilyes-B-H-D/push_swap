/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:04:15 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/23 18:07:47 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_init_b(t_stack *a, t_stack *b)
{
	t_stack	*curr;
	t_stack	*target;
	long	best_match;

	ft_current_index(a);
	ft_current_index(b);
	while (b)
	{
		best_match = LONG_MAX;
		curr = a;
		while (curr)
		{
			if (curr->val > b->val && curr->val < best_match)
			{
				best_match = curr->val;
				target = curr;
			}
			curr = curr->next;
		}
		if (best_match == LONG_MAX)
			b->trg = ft_find_min(a);
		else
			b->trg = target;
		b = b->next;
	}
}
