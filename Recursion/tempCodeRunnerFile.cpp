#include <iostream> 

using namespace std;

int fib(int &x, int c) 
{
    c = c - 1; 

    if (c == 0) return 1; 

    x = x + 1;

    return fib(x,c) * x;
}

int main() {
    int p = 5;
    cout << fib(p, p);
    return 0;
}