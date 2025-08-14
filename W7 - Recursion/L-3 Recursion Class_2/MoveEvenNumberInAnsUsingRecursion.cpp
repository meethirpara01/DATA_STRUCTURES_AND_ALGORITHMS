#include<iostream>
#include<limits.h>
using namespace std; 
void printArray(int arr[], int size, int index, vector<int> &ans) // CATCH TAKE Min BY REFRENCE
{
    // BASE CASE
    if (index >= size)
        return;

    // PROCCESING
    if (arr[index] % 2 == 0)
    {
        ans.push_back(arr[index]);
    }

    // RECURSIVE CALL
    printArray(arr, size, index + 1, ans);
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
    vector<int> ans;

    printArray(arr, size, 0, ans);
    cout << "EVEN NUMBERS IN ARRAY: " << endl;
    for (auto num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0; 
}