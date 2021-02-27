#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int count;
    
    count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return (count);
}

int main(void)
{
    printf("%i", ft_strlen("A L E X"));
}