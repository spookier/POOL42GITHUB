#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void    ft_init_matrix(int **tab, int size, int x, int y, int **sol, char *str);
int     **ft_create_matrix(int size);
void    ft_print_2d_array(int **tab, int size);
int 	param_invalid(char *input, int size);

int main(int argc, char *argv[])
{
	int size;
	int **troll;
	int **solution;

	size = 5;
	if(argc != 2 || param_invalid(argv[1], size))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	troll = ft_create_matrix(size);
	solution = ft_create_matrix(size);	
	ft_init_matrix(troll, size,0,0,solution,argv[1]);
	if (solution[0][0] == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_print_2d_array(solution, size);


	return (0);
}
