#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    
    if (n == 0)
	  return (0);
	  
    int i;

    i = 0;
    
    while(s1[i] && s2[i] && (s1[i] == s2[i]) && i < n - 1)
    {

       i++;
    }
    
    return (s2[i] - s1[i]);
}

int main(void) 
{
    char a[] = {"y"};
    char b[] = {"Ya"};
    
    printf("%d", ft_strncmp(a, b, 1));
}
  