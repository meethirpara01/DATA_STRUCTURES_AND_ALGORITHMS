#include<iostream>
using namespace std; 

int Count0and1(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;

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

    int ans = Count0and1(arr, size);
    cout << "Unique Element is:  " << ans <<endl; 
    
    return 0; 
}