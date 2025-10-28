#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#define EXIT_ERROR(a, s, msg) exit_error(a, s, msg, __FILE__, __LINE__)


# include <stdlib.h> 
# include <unistd.h>  
# include <stddef.h>  

typedef struct s_list
{
    int         value;
    int         index;
    int         keep;
    int         step;
    struct s_list   *next;
}   t_list;

/*libft_utils*/
int ft_atoi(const char *str);
size_t ft_strlen(const char *s);
char   **ft_split(char const *s, char c);
int ft_strcmp(const char *s1, const char *s2);





#endif
