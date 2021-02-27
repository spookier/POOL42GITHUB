#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{	
	int i;
	int result;

	i = 0;
	result = 0;
	if (power < 0)
		return 0;

	if (nb == 0 && power == 0)
		return 1;

	while (i < nb)
	{
		result = nb * nb;
		i++;		
	}
	return (result);
}


int main(void)
{
	printf("%d", ft_iterative_power(0, 0));
}
