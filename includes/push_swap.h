#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#define EXIT_ERROR(a, s, msg) exit_error(a, s, msg, __FILE__, __LINE__)


# include <stdlib.h> 
# include <unistd.h>  
# include <stddef.h>  

typedef struct s_node
{
    int         value;
    int         index;
    int         keep;
    int         step;
    struct s_node  *next;
}   t_node;

/*libft_utils*/
int ft_atoi(const char *str);
size_t ft_strlen(const char *s);
char   **ft_split(char const *s, char c);
int ft_strcmp(const char *s1, const char *s2);

/*stack_utils*/
void link_new_node(t_node **stack, int value);
void find_repeats(t_node *stack);
void purge_stack(t_node **stack);




#endif
