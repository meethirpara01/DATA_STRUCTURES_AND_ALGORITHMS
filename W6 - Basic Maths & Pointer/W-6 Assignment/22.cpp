#include<iostream>
using namespace std; 

void squre(int *p)
{
    int a = 10;
    p = &a;
    *p = (*p) * (*p);
    cout << a << endl; 
}

int main() 
{ 
    int a = 10;
    squre(&a);
    cout << a << endl; 
    return 0; 
}