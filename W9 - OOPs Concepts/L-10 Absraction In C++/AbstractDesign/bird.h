#include<iostream>
using namespace std;
#if !defined(BIRD_H)
#define BIRD_H

class Bird
{
    public:
        virtual void eat() = 0;
        virtual void fly() = 0;
        // CLASSES THAT INHERITS THIS CLASS 
        // HAS TO IMPLEMENT PURE VIRTUAL FUNCTIONS.
};

class Sparrow: public Bird
{
    public:
        void eat()
        {
            cout << "Sparrow is Eating" << endl;
        }

        void fly()
        {
            cout << "Sparrow is Flying" << endl;
        }

}


#endif // BIRD_H
