#include <stdio.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src, unsigned int nb)
{
	char *ptr_dest;            //créer ptr
	int i;
	
	i = 0;
	ptr_dest = dest;          //ptr sur 1ere lettre de dest
	while (*ptr_dest != '\0')
	{
	    ptr_dest++;         // ptr est a la fin de dest
	}      
	while (i < nb && src[i] != '\0')  
	{
	    *ptr_dest++ = src[i]; 
	    i++;
	}
	*ptr_dest = '\0';         
	return (dest);          
}

int main()
{
    char src[] = {"Ye boi"};
    char dest[] = {"Mais nan eee"};
    printf("%s", ft_strcat(dest, src, 8));
}