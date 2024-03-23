/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benhajdahmaneilyes <benhajdahmaneilyes@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:35:16 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/22 05:04:01 by benhajdahma      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str) || *str == ' '
			|| (*str >= 9 && *str <= 13)))
		return (1);
	while (*++str)
		if (!ft_isdigit(*str) && !(*str == ' ' || (*str >= 9 && *str <= 13)))
			return (1);
	return (0);
}

int	ft_error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a->next && a->val != n)
		a = a->next;
	if (a->val == n)
		return (1);
	return (0);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->val = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
