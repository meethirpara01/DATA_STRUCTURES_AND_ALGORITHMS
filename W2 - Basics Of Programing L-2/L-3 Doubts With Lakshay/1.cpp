#include<iostream>
#include "2.h"
using namespace std; 

void Func()
{
    cout << "Func Run Ho Gya!!!" << endl;
}

int main() 
{ 
    Func();
    FuncFrom2();
    
    cout << "All Function and File Working Fine" << endl; 

    return 0; 
}