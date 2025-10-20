#include<iostream>
using namespace std;
#if !defined(BIRD_H)
#define BIRD_H

// INTERFACE
class Bird
{
    public:
        virtual void eat() = 0;
        virtual void fly() = 0;
        // CLASSES THAT INHERITS THIS CLASS 
        // HAS TO IMPLEMENT PURE VIRTUAL FUNCTIONS.
};

// IMPLEMENTATION
class Sparrow: public Bird
{
    private:
        void eat()
        {
            cout << "Sparrow is Eating" << endl; 
        }

        void fly()
        {
            cout << "Sparrow is Flying" << endl;
        }
};

class Eagle: public Bird
{
    private:
        void eat()
        {
            cout << "Eagle is Eating" << endl; 
        }

        void fly()
        {
            cout << "Eagle is Flying" << endl;
        }
};

class Pigeon: public Bird
{
    private:
        void eat()
        {
            cout << "Pigeon is Eating Faster!" << endl; 
        }

        void fly()
        {
            cout << "Pigeon is Flying Faster!" << endl;
        }
};


#endif // BIRD_H
