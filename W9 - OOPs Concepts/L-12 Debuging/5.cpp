#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak() { cout << "Animal speaks" << endl; }
};

class Dog : public Animal
{
public:
    void speak() { cout << "Dog barks" << endl; }
};

int main()
{
    Animal *a = new Dog;
    a->speak(); // Output: "Dog barks"
    delete a;
    return 0;
}