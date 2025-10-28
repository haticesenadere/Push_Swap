#include "push_swap.h"

int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    if (ac == 1 || (ac == 2 && !av[1][0]))
    {
        return (0);
    }
    valid_arguments(ac, av,  &stack_a);
       
    return (0);
}




