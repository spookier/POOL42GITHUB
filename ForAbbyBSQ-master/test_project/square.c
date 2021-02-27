#include "square.h"


void ft_put_nbr(int nb)
{
    if (nb < 0)
        nb = -nb;
    else if (nb < 10)
        ft_putchar('0' + nb);
    else
    {
       ft_put_nbr(nb % 10);
       ft_put_nbr(nb / 10);
    }
}

//### STR ###
void ft_putchar(char c)
{
    write(1, &c, 1);
}

//### MATRIX ###
Matrix createMatrix(int size_x, int size_y)
{
    Matrix mat;

    mat.data = (int**)malloc(size_x * sizeof(int*));

    int x;

    x = 0;
    while (x < size_x)
    {
        mat.data[x] = (int*)malloc(size_y * sizeof(int));
        x++;
    }

    mat.size_x = size_x;
    mat.size_y = size_y;

    return (mat);
}


Matrix initMatrix(Matrix matrix, int value)
{
    int x;
    int y;

    y = 0;
    while (y < matrix.size_y)
    {
        x = 0;
        while (x < matrix.size_x)
        {
            matrix.data[x][y] = value;
            x++;
        }
        y++;
    }

    return (matrix);
}

void destroyMatrix(Matrix matrix)
{
    int x;

    x = 0;
    while (x < matrix.size_x)
    {
        free(matrix.data[x]);
        x++;
    }
    free(matrix.data);
}

void displayMatrix(Matrix matrix)
{
    int x;
    int y;

    y = 0;
    while (y < matrix.size_y)
    {
        x = 0;
        while (x < matrix.size_x)
        {
            ft_putchar('0' + matrix.data[x][y]);
            if (x < matrix.size_x - 1)
            {
                ft_putchar('.');
            }
            x++;
        }
        ft_putchar('\n');
        y++;
    }
}

//### SOLVER ###
int solveSqr(Matrix matrix)
{
    int ox;
    int oy;
    int os;
    
    ox = 0;
    oy = 0;
    os = 0;
	
    getBigSqrInMat(matrix, &ox, &oy, &os);

    if (os > 0)
    {
        setSqrInMap(matrix, ox, oy, os);
        return (1);
    }

    return (0);
}

void getBigSqrInMat(Matrix matrix, int* ox, int* oy, int* os)
{ 
    int s;
    int x;
    int y;
    
    s = 0;
    y = 0;
    while (y < matrix.size_y)
    {
        x = 0;
        while (x < matrix.size_x)
        {
            s = getMaxSqr(matrix, x, y);

            if (s > *os && (x <= *ox || y <= *oy))
            {
                *os = s;
                *ox = x;
                *oy = y;
            }
            x++;
        }
        y++;
    }
}

int getMaxSqr(Matrix matrix, int x, int y)
{
    int s;
    int dx;
    int dy;

    s = 0;
    while (x + s < matrix.size_x && y + s < matrix.size_y)
    {
        dx = 0;
        while (dx < s + 1)
        {
            dy = 0;
            while (dy < s + 1)
            {
                if(matrix.data[x + dx][y + dy] == 1)
                    return (s);
                dy++;
            }
            dx++;
        }
        s++;
    }
    return (s);
}

void setSqrInMap(Matrix matrix, int x, int y, int size)
{
    int dx;
    int dy;

    dy = 0;
    while (dy < size)
    {
        dx = 0;
        while (dx < size)
        {
            matrix.data[x + dx][y + dy] = 2;
            dx++;
        }
        dy++;
    }
}

