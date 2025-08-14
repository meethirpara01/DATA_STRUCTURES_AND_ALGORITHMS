#include<iostream>
using namespace std; 
void printArray(int arr[], int size, int index)
{
    // BASE CASE
    if (index >= size)
        return;

    // PROCCESING
    arr[index] *= 2;

    // RECURSIVE CALL
    printArray(arr, size, index + 1);
    return;
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

    printArray(arr, size, 0);
    for (auto num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0; 
}