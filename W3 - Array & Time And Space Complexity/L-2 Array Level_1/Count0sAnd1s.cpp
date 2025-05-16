#include<iostream>
using namespace std; 

void Count0and1(int arr[], int size)
{
    int zero = 0;
    int one = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            zero++;
        }
        else if (arr[i] == 1)
        {
            one++;
        }
    }

    cout << "ZERO'S ARE : " << zero << endl;
    cout << "ONE'S ARE : " << one << endl;
    
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

    Count0and1(arr, size);
    
    return 0; 
}