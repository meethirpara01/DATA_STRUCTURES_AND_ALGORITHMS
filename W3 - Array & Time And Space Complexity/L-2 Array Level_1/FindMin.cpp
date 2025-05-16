#include<iostream>
#include<limits.h>
using namespace std; 

int FindMin(int arr[], int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
    
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

    int ans = FindMin(arr, size);
    cout << "Minmum Element In Array Is : "<< ans << endl;
    
    return 0; 
}