#include "square.h"

#include <stdio.h>
#include <time.h>


int main(int argc, char *argv[])
{
	/*
    int sizex;
    int sizey;

    sizex = 30;
    sizey = 30;

    Matrix matrix;
    matrix = createMatrix(sizex, sizey);
    initMatrix(matrix, 0);
    
    srand(time(NULL));
    for (int x = 0; x < matrix.size_x; x++)
        for (int y = 0; y < matrix.size_y; y++)
            if (rand() % 100 >= 95)
                matrix.data[x][y] = 1;
    
    displayMatrix(matrix);
    ft_putchar('\n');*/

	if (argc == 2)
	{
		FILE* fichier = NULL;

		fichier = fopen(argv[1], "r");

		if (fichier != NULL)
		{
			// On peut lire et écrire dans le fichier
		}
		else
		{
			// On affiche un message d'erreur si on veut
			printf("Impossible d'ouvrir le fichier test.txt");
		}

		if (solveSqr(matrix))
		{
			displayMatrix(matrix);
		}
	}

    
    return (0);
}

