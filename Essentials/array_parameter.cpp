#include <iostream>
#include <stdio.h>

using namespace std;


void fun(int *a) {
    cout << sizeof(a) / sizeof(int) << endl;
}

int main() {
    int p[] = {2, 4, 6, 8, 10};

    fun(p);

    cout << sizeof(p) / sizeof(int) << endl;

    return 0;
}
