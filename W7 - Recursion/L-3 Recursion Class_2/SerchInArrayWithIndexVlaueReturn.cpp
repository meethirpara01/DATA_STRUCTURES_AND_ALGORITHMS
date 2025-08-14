#include<iostream>
using namespace std; 
int printArray(int arr[], int size, int index, int Target)
{
    // BASE CASE
    if (index >= size)
        return -1;

    // PROCCESING
    if (arr[index] == Target)
        return index;

    // RECURSIVE CALL
    int agekaAns = printArray(arr, size, index + 1, Target);
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

    int ans = printArray(arr, size, 0, Target);
    ans == -1 ? cout << "Target Not Found" << endl : cout << "Target Found " << ans << endl;
    cout << endl;

    return 0; 
}