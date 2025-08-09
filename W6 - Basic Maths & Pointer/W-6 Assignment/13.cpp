#include<iostream>
using namespace std; 
 
int main() 
{ 
    char b[] = "xyz"; 
    char *c = &b[0];
    cout << *c << endl;
    cout << c << endl;

    int arr[] = {1, 2, 3}; 
    int *ptr = &arr[0];
    cout << *ptr << endl;
    cout << ptr << endl;
    
    return 0; 
}