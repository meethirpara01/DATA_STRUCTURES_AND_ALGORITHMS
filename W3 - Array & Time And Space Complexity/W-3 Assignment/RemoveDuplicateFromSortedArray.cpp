#include<iostream>
using namespace std; 
// Approch For This Question 
// 2 Pointer Approch O(n)
void removeDuplicateAndSetElemetInKIndex(int arr[], int size)
{
    int i = 0;
    int j = 0;

    while (j < size)
    {
        if (arr[i] == arr[j])
            j++;
        else
            arr[++i] = arr[j++];
            // i++;
            // arr[i] == arr[j];;
            // j++;;
    }

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
    cout << "In Array Uniq Element Exsit In " << i + 1 << " Size.." << endl;
}


int main() 
{ 
    int size;
    cout << "Enter Size Of Array :" << endl; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element Of Array " << i << " : ";
        cin >> arr[i];
    }

    removeDuplicateAndSetElemetInKIndex(arr, size);
    
    return 0; 
}