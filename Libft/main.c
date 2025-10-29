#include "libft.h"
#include  <stdio.h>

int main()
{
  
    char  buffer[] = "1234567890"; 

   char *result =  ft_memmove(buffer + 2, buffer, 6);

  printf("%s\n", buffer);
  printf("%s\n", result);
  //ABCDEF
}



