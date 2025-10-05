int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;

    if (ac ==  1 || (ac == 2 && !av[1][0]))  //Algo adım 2. 
    {
       return (0);
    }
        valid_arguments(**av);
    return 0; 
}