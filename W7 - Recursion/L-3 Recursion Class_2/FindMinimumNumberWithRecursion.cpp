#include<iostream>
#include<limits.h>
using namespace std; 
void printArray(int arr[], int size, int index, int &Min) // CATCH TAKE Min BY REFRENCE
{
    // BASE CASE
    if (index >= size)
        return;

    // PROCCESING
    Min = min(Min, arr[index]);

    // RECURSIVE CALL
    printArray(arr, size, index + 1, Min);
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
    int Min = INT_MAX;

    printArray(arr, size, 0, Min);
    cout << "Minimum Number Is: " << Min << endl;

    return 0; 
}