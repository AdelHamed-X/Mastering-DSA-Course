#include <stdio.h>
#include <stdlib.h>



int main()
{
    // A pointer to an array of 3 integers in the stack
    int a[3][4];

    // The main array of pointers is in the stack 
    int *b[3];
    int **c;
    b[0] = (int *)malloc(sizeof(int) * 4);
    b[1] = (int *)malloc(sizeof(int) * 4);
    b[2] = (int *)malloc(sizeof(int) * 4);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    // The main array of pointers is in the heap and pointed to by c 
    c = (int **)malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++)
    {
        c[i] = (int *)malloc(sizeof(int) * 4);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

}
