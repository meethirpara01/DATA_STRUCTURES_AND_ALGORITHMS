#include<iostream>
using namespace std; 

bool FindTarget(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
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

    int target;
    cout << "Enter Target: " << endl; 
    cin >> target;

    bool ans = FindTarget(arr, size, target);
    (ans) ? cout << "Target Found" << endl : cout << "Target Not Found" << endl ;
    
    return 0; 
}