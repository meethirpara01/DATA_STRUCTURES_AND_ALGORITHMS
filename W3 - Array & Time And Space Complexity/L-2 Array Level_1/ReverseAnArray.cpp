#include<iostream>
#include<limits.h>
using namespace std; 

void ReverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        // arr[start] = arr[start] ^ arr[end];
        // arr[end] = arr[start] ^ arr[end];
        // arr[start] = arr[start] ^ arr[end];
        // int temp;
        // temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;
        start++;
        end--;
    }

    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}
int main() 
{ 
    int size;
    cout << "Enter Size of Array: " << endl; 
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element Arr[" << (i+1) << "] :" << endl;
        cin >> arr[i];
    }

    ReverseArray(arr, size);
    
    return 0; 
}