#include <stdio.h>

double taylor(int m, int n) {
    static double power = 1, factorial = 1;
    double result;

    if (n == 0)
        return 1;
    
    result = taylor(m, n - 1);
    power = power * m;
    factorial = factorial * n;
    return result + (power / factorial);
}

int main() {
    printf("%f\n", taylor(1, 10));
    return 0;
}