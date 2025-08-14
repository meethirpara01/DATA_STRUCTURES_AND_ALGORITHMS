#include<iostream>
using namespace std; 
bool printArray(int arr[], int size, int index, int Target)
{
    // BASE CASE
    if (index >= size)
        return false;

    // PROCCESING
    if (arr[index] == Target)
        return true;
    ++index;

    // RECURSIVE CALL
    bool agekaAns = printArray(arr, size, index, Target);
    return agekaAns;
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

    bool ans = printArray(arr, size, 0, Target);
    ans ? cout << "Target Found" << endl : cout << "Target Not Found" << endl;
    cout << endl;

    return 0; 
}