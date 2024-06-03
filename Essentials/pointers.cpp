#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x;
};

// ********** Dealing with stack portion of the memory *************
// int main() {
//     int a = 10;
//     int *p = &a;

//     cout << a << endl;
//     printf("Using pointer %d at address %d %d\n", *p, &a, p);

//     int A[5] = {2, 4, 6, 8, 10};
//     int *p1 = A;

//     for (int i = 0; i < 5; i++) {
//         printf("%d\n", *(p1 + i));
//     }

//     for (int i = 0; i < 5; i++) {
//         printf("%d\n", p1[i]);
//     }
// }

// ********* Dealing with Heap portion of the memory **************
int main() {
    int *p = new int[5];

    p[0] = 10;

    cout << p << endl;
    cout << *p << endl;

    cout << "********************" << endl;

    int *p1 = (int *)malloc(5 * sizeof(int));
    printf("%d\n", p1);

    // TODO Difference between printing an address variable using %d and %p
    // %d prints the address in base 10 %p prints the address in base 16    
    if (printf("%d\n", p1) == printf("%p\n", p1)) {
        cout << "ok" << endl; // won't output ok
    }

    cout << "********************" << endl;

    int *p6;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    printf("%d\n", sizeof(p6));
    printf("%d\n", sizeof(p2));
    printf("%d\n", sizeof(p3));
    printf("%d\n", sizeof(p4));
    printf("%d\n", sizeof(p5));
}
