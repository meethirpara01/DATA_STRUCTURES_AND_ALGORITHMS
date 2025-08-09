#include<iostream>
using namespace std; 
 
int main() 
{ 
    int a = 7;
    int* c= &a;
    c = c + 2;
    cout<< c << endl; // GARBAGE VALUE
    return 0; 
}