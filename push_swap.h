#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>

#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"

typedef struct s_stack
{
	int					value;
	int					index;
	int					push_cost; 
	bool				above_median; 
	bool				cheapest; 
	struct s_stack		*target_node;
	struct s_stack		*next; 
}	t_stack;

// errors
int				ft_error_syntax(char *str); 
int				ft_error_duplicate(t_stack *a, int n);
void			ft_free_stack(t_stack **stack);


void ft_swap(t_stack** stack);
void ft_rotate(t_stack** stack);

// utils
t_stack    *ft_find_min(t_stack *stack);
t_stack    *ft_find_max(t_stack *stack);
t_stack    *ft_find_last(t_stack *stack);
int			ft_stack_len(t_stack *stack);
void ft_rev_rotate(t_stack** stack);
char **parse(char *s);
void	ft_init_stack_a(t_stack **a, char **av);
 bool	ft_stack_sorted(t_stack *stack);
void	ft_current_index(t_stack *stack);
t_stack	*ft_get_cheapest(t_stack *stack);
void	ft_prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	ft_init_nodes_a(t_stack *a, t_stack *b);
void	ft_init_nodes_b(t_stack *a, t_stack *b);
// Operations
void	sa(t_stack	**a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	pa(t_stack **a, t_stack **b);

// sort algo
t_stack* 		ft_sort_three(t_stack* stack);
void			sort_stacks(t_stack **a, t_stack **b); //Turk algorithm


#endif