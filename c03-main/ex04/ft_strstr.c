#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	if (!*to_find)
		return (str);
		
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 1;
			while (to_find[i] && str[i] == to_find[i])
				i++;
			if (!to_find[i])
				return (str);
		}
		str++;
	}
	return (0);
}

int main(void)
{
    char t[] = {"Alexandru"};
    printf("%s", ft_strstr("ALEXANDRUAUREVOIR" ,"V"));
}
