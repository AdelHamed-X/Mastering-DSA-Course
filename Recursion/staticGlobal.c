#include <stdio.h>

int x = 0;
int fun(int n) {
    // static int x = 0;
    if (n > 0) {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main() {
    int x = 5;

    printf("%d\n", fun(x));
    printf("%d\n", fun(x));

    return 0;
}