#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while(s1[i] && s2[i] && (s1[i] == s2[i]))
    {
       i++;
    }

    return (s2[i] - s1[i]);
}


int main(void) 
{
    char a[] = {"Yes"};
    char b[] = {"Yesws"};
    
    printf("%d", ft_strcmp(a, b));
}
 