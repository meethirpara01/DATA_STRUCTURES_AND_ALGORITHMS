#include<iostream>
using namespace std; 
 
int main() 
{ 
    int* ptr = 0; 
    int a = 10;
    *ptr = a; // RUNTIME ERROR
    cout << *ptr << endl;
    return 0; 
}