#include <iostream>
#include "bird.h"
using namespace std;

void birdDoseSomething(Bird *&bird)
{
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();  
    bird->eat();
    bird->fly();
    bird->eat();
    bird->eat();
    bird->fly();
    bird->eat();

}

int main()
{
    Bird *bird = new Sparrow();
    // Sparrow *sp = new Sparrow();
    // sp->eat(); // I CAN NOT DO THIS BECAUSE Sparrow's MEMBERS ARE PRIVATE CAN NOT ACCESS DIRECTLY WE NEED TO USE GETER/SETTER METHOD AND WE CAN USE Bird CLASS AS AN INTERFACE BY MAKEING Bird PURE VIRTUAL FUNCTION
    birdDoseSomething(bird);

    cout << endl;
    cout << endl;

    bird = new Eagle();
    birdDoseSomething(bird);
    // EASY TO MAINTAIN AND EXTENDEBLE
    cout << endl;
    cout << endl;

    bird = new Pigeon();
    birdDoseSomething(bird);

    // Bird *b2 = new Bird(); // I CAN'T DO THAT
    return 0;
}