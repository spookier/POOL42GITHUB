#include <stdio.h>

int ft_atoi(char* str)
{
    int i;
    int sign;
	
    i = 0;
    while (str[i] == ' ')
        i++;
    sign = 1;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = sign * -1;
        i++;
    }
    int n;
    n = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        n = n * 10;
        n = n + (str[i] - '0');
        i++;
    }
    return (n * sign);
}


int main()
{
    printf("%d", ft_atoi("             -+++--+-++-+------+1238X6"));
    return (0);
}

