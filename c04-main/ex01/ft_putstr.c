#include <unistd.h>
#include <stdio.h>

// Sort le string dans la console

void ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(void)
{
    //ft_putchar('T');
    char h[] = {"HELP"};
    ft_putstr(h);
    printf("\n");
    printf("%c", *(h + 3));
    //printf("%s", ft_putstr("HELLO"));
}