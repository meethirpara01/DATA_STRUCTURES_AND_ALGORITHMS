#include <iostream>
using namespace std;

class abc
{
    public: 

        int x;
        int *y;

        abc(int _x, int _y) : x(_x), y(new int(_y)) {}

        // abc(const abc &obj)

        void print() const 
        {
            printf("X: %d\nPTR Y: %p\n Content of Y (*y): %d\n\n", x, y, *y);
        }
};

int main()
{
    abc a(1, 2);
    cout << "PRINT A\n";
    a.print();

    abc b = a;
    cout << "PRINT B\n";
    b.print();
    *b.y = 20;
    cout << "PRINT B\n";
    b.print();

    cout << "PRINT A\n";
    a.print();
    return 0;
}