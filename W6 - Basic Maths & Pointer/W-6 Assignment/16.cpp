#include<iostream>
using namespace std; 
 
int main() 
{ 
    char *ptr;  // char *ptr = 0;
    char str[] = "abcdefgh";
    ptr = str;
    ptr += 5;
    cout << ptr << endl;
    return 0; 
}