#include <stdio.h>

#define SIZE 50000
int A[SIZE][SIZE];

int main(void)
{
    int S, i, j;
    S = 0;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            S += A[i][j];
    return 0;
}