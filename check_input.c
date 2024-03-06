#include "./push_swap.h"

int ft_is_valid_input(int ac, char **av)
{
    int i;
    int j;
    int k;
    
    i = 1;
    while (i < ac) {
        j = 0;
        while (av[i][j] != '\0') {
            if (!ft_isdigit(av[i][j])) {
                return 0; 
            }
            j++;
        }

        k = i + 1;
        while (k < ac) {
            if (ft_atoi(av[i]) == ft_atoi(av[k])) {
                return 0;
            }
            k++;
        }
        i++;
    }
    return 1;
}