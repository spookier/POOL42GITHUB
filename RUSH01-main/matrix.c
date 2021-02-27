#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int     ft_calc_view(int *line, int size)
{
	int i;
	int max;
	int count;

	max = 0;
	count = 0;
	i = 0;
	while (i < size)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

void	ft_print_2d_array(int **tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(tab[i][j] + '0');
			j++;
			ft_putchar(' ');
		}
		i++;
		ft_putchar('\n');
	}
}

int	**ft_create_matrix(int size)
{
	int i;
	int j;
	int **tab;

	tab = malloc (sizeof (int*) * size);
	i = 0;
	while (i < size)
	{
		j = 0;
		tab[i] = malloc (sizeof (int) * size);
		while(j < size)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

int	ft_count_line_value(int size)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (i < size + 1)
	{
		count += i;
		i++;
	}
	return (count);
}

int	ft_valid_col(int **tab, int size)
{
	int i;
	int j;
	int count;

	i = 0;
	while( i < size)
	{
		j = 0;
		count = 0;
		while(j < size)
		{
			count += tab[j][i];
			j++;
		}
		if(count != ft_count_line_value(size))
			return 0;	
		i++;
	}
	return 1;
}
int	ft_valid_row(int **tab, int size)
{	
	 int i;
	 int j;
	 int count;
	 
	 i = 0;
	 while( i < size)
	 {
		 j = 0;
		 count = 0;
		 while(j < size)
		 {
			 count += tab[i][j];
			 j++;
		 }
		 if(count != ft_count_line_value(size))
			 return 0;
		 i++;
	 }
	 return 1;
}
int	ft_valid_col_up(int** tab, int size, char *str)
{
	int i;
	int j;
	int tmp;
	int *selection;

	i = 0;
	selection = malloc(sizeof (int) * size);
	while(i < size)
	{
		tmp = str[2*i] - '0';
		j = 0;
		while(j < size)
		{
			selection[j] = tab[j][i];
			j++;
		}
		if(ft_calc_view(selection, size) != tmp)
			return (0);
		i++;
	}
	return (1);
}
int	ft_valid_col_down(int **tab, int size, char *str)
{
	int i;
	int j;
	int tmp;
	int *selection;


	i = 0;
	selection = malloc(sizeof (int) * size);
	while(i < size)
	{
		tmp = str[(2 * size) + 2*i] - '0';
		j = 0;
		while(j < size)
		{
			selection[j] = tab[size - (j+1)][i];
			j++;
		}
		if(ft_calc_view(selection, size) != tmp)
			return 0;
		i++;
	}
	return 1;
}
int 	ft_valid_row_left(int **tab, int size, char *str)
{
	 int i;
	 int tmp;
	
	 i = 0;
	 while(i < size)
	 {
		 tmp = str[(2*i) + (4 * size)] - '0';
		 if(ft_calc_view(tab[i], size) != tmp)
			 return 0;
		 i++;
	 }
	 return 1;
}
int	ft_valid_row_right(int **tab, int size, char *str)
{
	 int i;
	 int j;
	 int tmp;
	 int *selection;
	 
	 i = 0;
	 selection = malloc(sizeof (int) * size);
	 while(i < size)
	 {
		 tmp = str[(6 * size) + 2*i] - '0';
		 j = 0;
		 while(j < size)
		 {
			 selection[j] = tab[i][size - (j+1)];
			 j++;
		 }
		 if(ft_calc_view(selection, size) != tmp)
			return 0;
		 i++;
	 }
	 return 1;
}
int 	ft_num_is_in_line(int **tab, int size, int num, int x, int y)
{
	int i;

	i = 0;
	while(i < size)
	{
		if( (tab[x][i] == num)
			|| (tab[i][y] == num))
		{
			return 1;
		}
		i++;
	}
	return 0;
}
int 	ft_valid_matrix(int **tab, int size, char *str)
{
	if(!ft_valid_row(tab,size) || !ft_valid_col(tab,size))
		return 0;
	if(!ft_valid_col_up(tab,size,str))
		return 0;
	if(!ft_valid_col_down(tab,size,str))
		return 0;
	if(!ft_valid_row_left(tab,size,str))
		return 0;
	if(!ft_valid_row_right(tab,size,str))
		return 0;
	return 1;
}
int	**ft_clone_matrix(int** tab, int size)
{
	int i;
	int j;
	int **new_tab;


	i = 0;
	new_tab = malloc(sizeof (int*) * size);
	while(i < size)
	{
		new_tab[i] = malloc(sizeof (int) * size);
		j = 0;
		while (j < size)
		{
			new_tab[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	return new_tab;
}
void	ft_init_matrix(int **tab, int size, int x, int y, int **sol, char *str)
{
	int i;

	i = 0;
	while (i < size)
	{
		if( !ft_num_is_in_line(tab,size,i+1,x,y))
		{
			tab[x][y] = i+1;
			if(x < size - 1)
			{
				ft_init_matrix(tab, size,x+1,y,sol,str);
			}
			else if(y < size-1) {
				ft_init_matrix(tab, size,0,y+1,sol,str);
			}
		}
		i++;
	}
	if(x == (size - 1) && y == (size - 1))
	{
		if(ft_valid_matrix(tab, size, str))
		{
			i = 0;
			int **tmp = ft_clone_matrix(tab, size);
			while(i<size)
			{
				sol[i] = tmp[i];
				i++;
			}
			//ft_print_2d_array(tab, size);
		}
	}
	tab[x][y] = 0;

}
