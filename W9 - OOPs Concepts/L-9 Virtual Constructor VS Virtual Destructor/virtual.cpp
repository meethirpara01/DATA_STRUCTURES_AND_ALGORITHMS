#include <iostream>
using namespace std;

class Base
{
    public:
        Base()
        {
            cout << "Base Ctor" << endl;
        }

        virtual ~Base()
        {
            cout << "Base Dtor" << endl;
        }
};

class Derived : public Base
{
    int *a;
    public:
        Derived()
        {
            a = new int[1000];
            cout << "Derived Ctor" << endl;
        }

        ~Derived()
        {
            cout << "Derived Dtor" << endl;
        }
};


int main()
{
    Base *b = new Derived();
    delete b;
    return 0;
}