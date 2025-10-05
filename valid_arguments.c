#include <stdlib.h>
void valid_argumenst(int ac, char **av, t_list **stack_a)
{
    char **args;
    int i;

    args = NULL;

    if (ac == 2)
    {
        args = ft_split(av[1], ' ');
        if (!args || !args[0])
        {
            free_split(args);
            exit(0); 
        }
        
    }
    else 
        args = av + 1;
    i = 0;
    while (args[i])
    {
        if (!is_valid_number(args[i]))
        {
            error_message(stack_a, args, "Error\n");
        }
        i++;
    }
    

    is_valid_number(av[1]);
}

int is_valid_number(char *s) // Girdinin geçerki sayı formatında olup olmadığını kontrol ediyoruz. 
{
    int i;
    i = 0;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    if (!s[i])
    {
        return (0);
    }
    while (s[i])
    {
        if (!is_digit(s[i]))
        {
            return (0);
        }
        i++;
    }

    return (1);
}

void free_split(char **split)
{
    int i;
    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
    
    
}

void exit_error(t_list **a, char **split, const char *mes, const char *file, int line)
{
    write(2, "Error: ", 7);
    if (mes)
    {
        write(2, msg, ft_strlen(msg));
    }
    write(2, "\n" ,1);
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

#define EXIT_ERROR(a, s, msg) exit_error(a, s, msg, __FILE__, __LINE__)