#include<iostream>
using namespace std; 

int FindTarget(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + (end - start)) / 2;

    while (start <= end)
    {
        if (arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            start = mid + 1;
        else if(arr[mid] > target)
        // else 
            end = mid - 1;
        
        mid = (start + (end - start)) / 2;
    }

    return -1;
}

int main() 
{ 
    int size;
    cout << "Enter Size Of Array :" << endl; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << " Enter " << i + 1 << " Element : " ;
        cin >> arr[i];
    }

    int target;
    cout << "Enter Target :" << endl; 
    cin >> target;

    int ans = FindTarget(arr, size, target);
    (ans != -1) ? cout << "Target Found" << endl : cout << "Target Not Found" << endl;
    
    return 0; 
}