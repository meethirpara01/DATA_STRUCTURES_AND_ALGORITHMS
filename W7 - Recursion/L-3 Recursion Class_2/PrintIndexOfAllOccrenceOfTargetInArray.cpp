#include<iostream>
using namespace std; 
void printArray(int arr[], int size, int index, int Target, vector<int> &ans)
{
    // BASE CASE
    if (index >= size)
        return;

    // PROCCESING
    if (arr[index] == Target)
        ans.push_back(index);   // ALSO SIMPLEY WE CAN cout << index << " ";

    // RECURSIVE CALL
    printArray(arr, size, index + 1, Target, ans);
    return;
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

    int Target;
    cout << "Enter Target : "; 
    cin >> Target;

    vector<int> ans;

    printArray(arr, size, 0, Target, ans);
    cout << endl;

    for(auto num : ans)
        cout << num << " ";
    cout << endl;

    return 0; 
}