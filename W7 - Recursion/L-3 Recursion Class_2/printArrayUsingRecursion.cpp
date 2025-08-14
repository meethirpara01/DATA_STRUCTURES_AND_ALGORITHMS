#include<iostream>
using namespace std; 
void printArray(int arr[], int size, int index)
{
    // BASE CASE
    if (index >= size)
        return;

    // PROCCESING
    cout << arr[index] << " ";
    index++;

    // RECURSIVE CALL
    printArray(arr, size, index);
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

    cout << "Array Element : " << endl;
    printArray(arr, size, 0);
    cout << endl;

    return 0; 
}