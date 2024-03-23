/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iben-haj <iben-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:04:12 by iben-haj          #+#    #+#             */
/*   Updated: 2024/03/23 18:17:41 by iben-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				val;
	int				idx;
	int				cost;
	bool			above_med;
	bool			cheapest;
	struct s_stack	*trg;
	struct s_stack	*next;
}					t_stack;
long				ft_atol(const char *s);
void				cost(t_stack *a, t_stack *b);
void				set_target(t_stack *a, t_stack *b);
void				set_cheapest(t_stack *stack);
int					ft_error_syntax(char *str);
int					ft_error_duplicate(t_stack *a, int n);
void				ft_free_stack(t_stack **stack);
void				ft_swap(t_stack **stack);
void				ft_rotate(t_stack **stack);
t_stack				*ft_find_min(t_stack *stack);
t_stack				*ft_find_max(t_stack *stack);
t_stack				*ft_find_last(t_stack *stack);
int					ft_stack_len(t_stack *stack);
void				ft_rev_rotate(t_stack **stack);
void				ft_init_stack(t_stack **a, char **av);
bool				ft_stack_sorted(t_stack *stack);
void				ft_current_index(t_stack *stack);
t_stack				*get_cheapest(t_stack *stack);
void				prep_for_push(t_stack **a, t_stack *top_node,
						char stack_name);
void				ft_init_b(t_stack *a, t_stack *b);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				ft_sort_three(t_stack **stack);
void				sort_stacks(t_stack **a, t_stack **b);

#endif