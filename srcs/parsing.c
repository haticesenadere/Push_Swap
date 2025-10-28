#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

void	analyze_input(int ac, char **av, t_list **stack_a)
{
	char	**args;
	int		is_split_needed;

	is_split_needed = 0;
	args = NULL;
	if (ac == 2) // tek argümanlı girdi, mesela "1 0 3 5"
	{
		args = ft_split(av[1], ' ');
		if (!args || !args[0])
		{
			free_split(args);
			exit(0);
		}
		is_split_needed = 1;
	}
	else // klasik olan zaten
		args = av + 1;
	safe_stack(stack_a, args);
	if (is_split_needed)
		free_split(args);
}


void	safe_stack(t_list **stack_a, char **args)
{
	int		i;
	long	num;

	i = 0;
	while (args[i])
	{
		if (!num_format_ok(args[i]))
			EXIT_ERROR(stack_a, args, "Invalid number format");
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			EXIT_ERROR(stack_a, args, "Number out of integer range");
		add_node_to_stack(stack_a, (int)num);
		i++;
	}
	check_duplicates(*stack_a);
}