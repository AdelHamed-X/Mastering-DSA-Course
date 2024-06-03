#include <iostream>
#include <stdio.h>
using namespace std;


struct Rectangle
{
    int length;
    int breadth;
    char x;
};

void fun(struct Rectangle &p) {
    p.length++;
    cout << "Length " << p.length << '\n' << "Breadth" << p.breadth << endl;
}

int main() {
    struct Rectangle r1 = {10, 5};

    fun(r1);

    printf("Length %d\nBreadth %d\n", r1.length, r1.breadth);
}