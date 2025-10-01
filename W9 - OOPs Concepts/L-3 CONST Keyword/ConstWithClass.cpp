#include<iostream>
using namespace std;

class abc
{
    mutable int x;
    int *y;
    const int z;

    public:
        // abc(int _x, int _y, int _z = 0) // DEFAULT ARGUMENT 
        // {
        //     x = _x;
        //     y = new int(_y);
        //     z = _z;
        // }

        abc(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z)
        {
            cout << "INITIALIZATION LIST " << endl;
        }

        int getX() const
        { 
            return x;
        }

        void chngeX(int _valX) const 
        {
            x = _valX;
        }

        int getY() const
        { 
            return *y;
        }

        void chngeY(int _valY)
        {
            *y = _valY;
        }

        int getZ() const
        { 
            return z;
        }
};

void printABC(const abc &A) // IT'S TAKE COST OBJECT AS AN PAREMETER BY REFRENCE
{
    // IF YOU TAKE AN CONSTENT OBJECT IN ARGUMENT THAN ALL CALLED METHOD SHOULD BE CONSTENT AND IT MEAN IT CAN'T CHANGE ANY DATA MEMBERS
    cout << A.getX() << endl;
    cout << A.getY() << endl;
    cout << A.getZ() << endl;
    // A.chngeX(10); // I CAN NOT DO THIS BECAUSE changeX MATHOD IS NON-CONST
    // BUT IF YOU WANT TO CHANGE HERE THAT FIRSY MAKE MATHOD CONST AND THAT USE MUTABLE KEYWORD BUT IT'S BAD PRECTICE
    A.chngeX(10);

    cout << "AFTER CHANGE " << endl;
    cout << A.getX() << endl;
    cout << A.getY() << endl;
    cout << A.getZ() << endl;
}

int main()
{
    abc A(1, 2, 3);
    printABC(A);
    
    return 0;
}