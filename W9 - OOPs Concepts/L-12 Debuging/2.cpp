#include <iostream>
using namespace std;

class Base
{
public:
    Base(int x) : value(x) {}
    void display() { cout << "Base: " << value << endl; }

private:
    int value;
};

class Derived : public Base
{
public:
    Derived(int y) : Base(y) {} // Call the base class constructor
    void show() { cout << "Derived: " << endl; }
};

int main()
{
    Base *ptr = new Derived(10);
    ptr->display(); // Output: "Base: 10"
    // ptr->show(); Error: 'show' is not a member of 'Base'
    delete ptr;
    return 0;
}