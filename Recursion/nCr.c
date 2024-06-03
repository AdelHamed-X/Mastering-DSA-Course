#include <stdio.h>

// This formulae helps in the scenario where i have such a large group
// and i need to choose a unique subset of that group where order doesn't matter

int fact(int n) {
    if (n == 0) return 1;
    return fact(n - 1) * n;
}

int nCr(int n, int r) {
    int fact_n = fact(n);
    int fact_r = fact(r);
    return fact_n / (fact_r * fact(n - r));
}

// for pascal's triangle
int NCR(int n, int r) {
    if (n == r || r == 0)
        return 1;
    return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

int main () {
    printf("%d\n", nCr(2, 2));
    // printf("%d\n", NCR(100000, 5));
    return 0;
}