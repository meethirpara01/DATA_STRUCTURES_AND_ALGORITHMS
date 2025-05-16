#include<iostream>
#include<limits.h>
using namespace std; 

void ReverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        if (start == end)
        {
            cout << arr[start] << " ";
        }
        else
        {
            cout << arr[start] << " ";
            cout << arr[end]<< " ";
        }
        start++;
        end--;
    }
    
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