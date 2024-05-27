#include <stdio.h>

// This takes n activation records in the stack
int power1(int m, int n) {
    if (n == 0)
        return 1;
    return power1(m, n - 1) * m;
}

// This method creates only 6 activation records in the stack
int power(int m, int n){
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power(m * m, n / 2);
    else
        return m * power(m, n - 1);
}

// only 1 stack frame is created
int power2(int m, int n){
    int p = m;
    for (int i = 1; i < n; i++) {
        p = p * m;
    }
    return p;
}


int main() {
    int m = 2;
    int n = 9;

    printf("%d\n", power1(m, n));
    printf("%d\n", power(m, n));
    printf("%d\n", power2(m, n));

    return 0;
}