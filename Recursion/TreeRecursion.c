#include <stdio.h>


int fun(int n) {
    if (n > 0) {
        printf("%d\n", n);
        fun(n - 1);
        fun(n - 1);
    }
    return 0;
}


int main() {
    fun(3);
    return 0;
}