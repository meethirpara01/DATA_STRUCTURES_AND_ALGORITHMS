#include<iostream>
using namespace std; 
 
int main() 
{ 
    int arr[] = {4, 5, 6, 7};
    int *p = (arr + 1);
    cout << *p + 9 << endl; 
    cout << *arr + 9 << endl; 
    return 0; 
}