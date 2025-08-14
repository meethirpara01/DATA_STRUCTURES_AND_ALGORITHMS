#include<iostream>
#include<limits.h>
using namespace std; 
void printArray(int arr[], int size, int index, int &MAX) // CATCH TAKE Min BY REFRENCE
{
    // BASE CASE
    if (index >= size)
        return;

    // PROCCESING
    MAX = max(MAX, arr[index]);

    // RECURSIVE CALL
    printArray(arr, size, index + 1, MAX);
}

int main() 
{ 
    int size;
    cout << "Enter Size Of Array : "; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Vlaue " << i << " Of Array : ";
        cin >> arr[i];
    }
    int MAX = INT_MIN;

    printArray(arr, size, 0, MAX);
    cout << "Maximum Number Is: " << MAX << endl;

    return 0; 
}