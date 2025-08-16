#include<iostream>
using namespace std; 

int BinarySearch(int arr[], int start, int end, int target)
{
    int mid = start + (end - start) / 2;

    // BASE CASE
    if (start > end)
        return -1;

    // PROCCESING
    if (arr[mid] == target)
        return mid;

    // RECURSIVE CALL
    if (arr[mid] < target)
        return BinarySearch(arr, mid + 1, end, target);
    else
        return BinarySearch(arr, start, mid - 1, target);
}

int main() 
{ 
    int size;
    cout << "Enter Size Of Array: " ; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " Element Of Array: ";
        cin >> arr[i];
    }

    int target;
    cout << "Enter Your Target: ";
    cin >> target;

    int ans = BinarySearch(arr, 0, size - 1, target);
    (ans != -1) ? cout << "Target Found At: " << ans << endl : cout << "Target Not Found" << endl;
    
    return 0; 
}