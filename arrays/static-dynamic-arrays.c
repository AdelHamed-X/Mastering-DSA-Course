#include <stdio.h>
#include <stdlib.h>

int main () {
    int *p, *q;

    p = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        p[i] = i;
    }

    

    q = (int *)malloc(sizeof(int) * 10);
    for (int i = 0;i < 5; i++) {
        q[i] = p[i];
    }

    free(p);
    p = q;
    q = NULL;
    
    for (int i = 0; i < 5; i++) {
        printf("%d \n", *(p + i));
    }
}