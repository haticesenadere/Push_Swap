//Gelen Sayıları kontrol et. Geçerli bir sayı mı değil mi diye? is_valid_number
// Tekrar eden sayı bulunup, bulunmadığını kontrol et
// İnt sınırlarını aşıp aşmadığını kontrol ediyoruz


#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"
void valid_arguments(int ac, char **av, t_list **stack_a) // Kullanıcı girdisinin farklı olması durumu  
{
    char **args;
    int i;
    int is_split_needed;

    is_split_needed = 0;
    args = NULL;

    if (ac == 2) // tek argümanlı girdiyi yönetir, mesela "1 0 3 5"
    {
        args = ft_split(av[1], ' '); 
        if (!args || !args[0])
        {
            free_split(args);
            exit(0); 
        }
        is_split_needed = 1;
    }
    else 
        args = av + 1;
    
        safe_stack(stack_a, args);

    if (is_split_needed)
        free_split(args);
}

void safe_stack(t_list **stack_a, char **args)
{
    int i;
    long num;
    i = 0;
       while (args[i])
    {
        if (!is_valid_number(args[i])) // FOrmat kontorlü yaptık
        {
            exit_error(stack_a, args, "Error\n");
        }

        num = ft_atol(args[i]);
              if (num > INT_MAX || num < INT_MIN) // int sınırlarını aşıp aşmadığını kontorl ettim 
            EXIT_ERROR(stack_a, args, "Number out of integer range");

         add_node_to_stack(stack_a, (int)num);
        i++;
    }

    check_duplicates(*stack_a); // Tekrar eden sayı kontrolü yaptık
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
        write(2, mes, ft_strlen(mes));
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