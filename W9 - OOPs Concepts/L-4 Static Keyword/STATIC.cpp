#include <iostream>
using namespace std;

// STATIC WITH DATA MEMBER 
class abc 
{
    public:
        static int x, y;

        void print() const 
        {
            cout << x << " " << y << endl;
        }
};

// STATIC WITH METHODS
class xyz 
{
    public:
        int a, b;

        xyz() : a(0), b(0) {}

        static void print() 
        {
            // CAN'T ACCESSIBLE THIS KEYWORD IN THIS STATIC METHOD
            printf("I am in Static %s\n", __FUNCTION__);
        }
};

int abc::x;
int abc::y;

int main()
{
    // STATIC WITH DATA MEMBER 
    abc obj1;
    obj1.x = 1; // ALSO YOU CAN abc::x = 1;
    obj1.y = 2; // ALSO YOU CAN abc::y = 2;
    obj1.print();
    abc obj2;
    obj2.x = 10;
    obj2.y = 20;
    obj1.print();
    obj2.print();


    // STATIC WITH METHODS
    xyz obj3;
    xyz::print();
    xyz obj4;
    xyz::print();
    xyz::print();


    return 0;
}