#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	exit_error(t_list **a, char **split, const char *msg,
			const char *file, int line)
{
	write(2, "Error: ", 7);
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	write(2, "at ", 3);
	write(2, file, ft_strlen(file));
	write(2, ":", 1);
	ft_putnbr_fd(line, 2);
	write(2, "\n", 1);
	if (a && *a)
		free_stack(a);
	if (split)
		free_split(split);
	exit(1);
}