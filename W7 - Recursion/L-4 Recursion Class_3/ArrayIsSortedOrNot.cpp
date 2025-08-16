#include<iostream>
using namespace std; 
bool ArrayIsSortedOrNot(int arr[], int size, int index)
{
    // BASE CASE
    if (index >= size)
        return true;

    // PROCEESSING
    if (arr[index] > arr[index - 1])
    {
        // RECUSIVE CALL
        bool agekAns = ArrayIsSortedOrNot(arr, size, index + 1);
        return agekAns;
    }
    else
        return false;  
}
int main() 
{ 
    int size;
    cout << "Eneter Size Of Array: "; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << "Element Of Array: " << endl;
        cin >> arr[i];
    }

    bool ans = ArrayIsSortedOrNot(arr, size, 1);
    ans ? cout << "Array Is Sorted!" << endl : cout << "Array Is Not Sorted!" << endl;
    
    return 0; 
}