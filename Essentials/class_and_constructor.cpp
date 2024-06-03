#include <iostream>

using namespace std;

class Rectangle
{
    public:
    int length;
    int breadth;
    Rectangle() {
        length = 0;
        breadth = 0;
    }
    int area() {
        return length * breadth;
    }
    void changeLength(int l) {
        length = l;
    }
};


int main() {
    int l, b;
    cin >> l >> b;

    Rectangle r();    

    cout << r.area() << endl;
}