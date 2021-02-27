#include <stdio.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	char *ptr_dest;            //créer ptr
	int i;
	
	i = 0;
	ptr_dest = dest;          //ptr sur 1ere lettre de dest
	while (*ptr_dest != '\0')
	{
	    ptr_dest++;         // ptr est a la fin de dest
	}      
	while (src[i] != '\0')  
	{
	    *ptr_dest++ = src[i]; // ajoute src a la fin de dest
	    i++;
	}
	*ptr_dest = '\0';         
	return (dest);          //retour de dest + ptr
}

int main()
{
    char src[] = {"Ye boi"};
    char dest[] = {"Mais nan eee"};
    printf("%s", ft_strcat(dest, src));
}