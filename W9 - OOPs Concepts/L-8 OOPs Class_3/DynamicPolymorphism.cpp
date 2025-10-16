#include <iostream>
using namespace std;

// without virtual early binding, static binding
// with virtual late binding, dynamic binding

class Animal
{
public:
    // virtual
    virtual void sound()
    {
        cout << "Animal makes a sound" << endl;
    }

    virtual ~Animal()
    {
        cout << "Animal DTOR" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog is barking" << endl;
    }

    ~Dog()
    {
        cout << "Dog DTOR" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Cat is meowing" << endl;
    }

    ~Cat()
    {
        cout << "Cat DTOR" << endl;
    }
};

class Parrot : public Animal
{
public:
    void sound() override
    {
        cout << "Parrot Mitthu Mitthu" << endl;
    }

    ~Parrot()
    {
        cout << "Parrot DTOR" << endl;
    }
};

void sound(Animal *animal)
{
    animal->sound(); // POLYMORPHIC
    // animal->sound IS BEHAVING AS PER REQUIRED OBJECT ALLOCATED AT RUNTIME
}

int main()
{
    // without virtual And early binding, static binding
    // Animal *animalPtr;
    // Dog dogObj;
    // Cat catObj;

    // animalPtr = &dogObj;
    // animalPtr->sound(); // Output: "Dog barks"

    // // animalPtr = &catObj;
    // // animalPtr->makeSound(); // Output: "Cat meows"


    // with virtual late binding, dynamic binding
    Animal *animal = new Dog();
    sound(animal);
    
    animal = new Cat();
    sound(animal);
    
    animal = new Parrot();
    sound(animal);

    delete animal;
    return 0;
}
