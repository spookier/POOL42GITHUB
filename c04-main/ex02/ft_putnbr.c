#include <stdio.h>
#include <unistd.h>


void ft_putchar(char c)
{
  write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
  unsigned int _nbr;

  if(nbr < 0)
  {
    ft_putchar('-');
    _nbr = -nbr;
  }
  else
  {
    _nbr = nbr;
  }

  if(_nbr <= 9)
  {
    ft_putchar('0' + _nbr);
  }
  else
  {
    ft_putnbr(_nbr / 10);
    ft_putnbr(_nbr % 10);
  }
}

/*
123

12 3
1 2
1
*/

int main(void)
{
  ft_putnbr(-2147483648); // Quand taille de int max négatif (-2147483648) converti en positif ça depasse le int max positif (2147483647)

  ft_putnbr(1);
	ft_putnbr(8);

  return 0;
}
