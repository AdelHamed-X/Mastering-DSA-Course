#include <iostream>

using namespace std;

int add(int a, int b) {
    a++;

    cout << a << endl;

    return 0;
}


int main() {
    int num1 = 10, num2 = 5;

    add(num1, num2);

    cout << num1 << endl;

    return 0;
}