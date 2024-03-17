#include "./push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = parse(av[1]);
	ft_init_stack_a(&a, av + 1);
	if (!ft_stack_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a);
		else if (ft_stack_len(a) == 3)
			ft_sort_three(a);
		else
			sort_stacks(&a, &b);
	}
	ft_free_stack(&a);
	return (0);
}
