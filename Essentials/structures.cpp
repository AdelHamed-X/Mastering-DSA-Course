#include <iostream>
#include <stdio.h>
using namespace std;


struct Rectangle
{
    int length;
    int breadth;
    char x;
};


int main() {
    struct Rectangle r1={10,5};

    cout << sizeof(r1);
}