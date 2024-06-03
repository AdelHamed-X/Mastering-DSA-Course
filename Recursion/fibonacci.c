#include <stdio.h>

// Iterative solution for fibonacci
int fib(int n) {
    int t0 = 1, t1 = 1, s, i;
    
    if (n <= 1) return n;
    for (i = 2; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

// Recursive solution for fibonacci
int fib1(int n) {
    if (n <= 1) return n;
    return fib1(n - 1) + fib1(n - 2);
}

// Improving memory consumption on recursive solution (MEMOIZATION)
int fib2(int n) {
    static int A[10];

    if (n <= 1) {
        A[n] = n;
        return n;
    }
    if (A[n - 2] == 0) 
    {
        A[n - 2] = fib2(n - 2);
    } else if (A[n - 1] == 0)
    {
        A[n - 1] = fib2(n - 1);
    }

    return fib(n - 1) + fib2(n - 2);   
}

int main() {
    printf("%d\n", fib(1));
    // printf("%d\n", fib1(10));
    // printf("%d\n", fib2(10));

    return 0;
}