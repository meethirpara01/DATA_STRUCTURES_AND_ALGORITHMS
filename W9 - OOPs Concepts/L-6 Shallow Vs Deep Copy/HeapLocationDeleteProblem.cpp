#include <iostream>
using namespace std;

class abc
{
    public: 

        int x;
        int *y;

        abc(int _x, int _y) : x(_x), y(new int(_y)) {}

        // DEFAULT COPY CONSTRUCTOR : IT DOSE SHALLOW COPY
        abc(const abc &obj)
        {
            x = obj.x;
            y = obj.y;
        }

        // SMART DEEP COPY
        // abc(const abc &obj)
        // {
        //     x = obj.x;
        //     y = new int(*obj.y);
        // }

        void print() const 
        {
            printf("X: %d\nPTR Y: %p\n Content of Y (*y): %d\n\n", x, y, *y);
        }

        ~abc()
        {
            delete y;
        }
};

int main()
{
    abc *a = new abc(1, 2);
    abc b = *a;
    delete a;
    b.print();
    return 0;
}