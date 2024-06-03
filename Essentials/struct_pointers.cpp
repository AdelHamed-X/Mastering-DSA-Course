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
    struct Rectangle r = {10, 5};

    struct Rectangle *p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p = &r;

    cout << p->length << endl;
    (*p).length = 8;
    cout << p->length << endl;
}