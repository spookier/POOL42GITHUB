#ifndef _SQUARE_H
#define _SQUARE_H

#include <stdlib.h>
#include <unistd.h>

//### STR ###
void ft_putchar(char c);

//### MATRIX ###
typedef struct 
{
    int** data;
    int size_x;
    int size_y;
} Matrix;


Matrix createMatrix(int size_x, int size_y);        //Allocate memory to the matrix
Matrix initMatrix(Matrix matrix, int value);        //Define the matrix cells to a value
void destroyMatrix(Matrix matrix);                  //Free the memory used by the matrix

void displayMatrix(Matrix matrix);                  //display the matrix values

//### FILE ###


//### CONVERTER ###

//### SOLVER ###
int solveSqr(Matrix matrix);

void getBigSqrInMat(Matrix matrix, int* ox, int* oy, int* os);
int getMaxSqr(Matrix matrix, int x, int y);
void setSqrInMap(Matrix matrix, int x, int y, int size);

#endif
