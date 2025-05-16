#include<iostream>
using namespace std; 
// This Question Approches
// 1. IndexBase Negetive Marking O(n)
// 2. Sorting + Swaping Set Evrey Element Their position O(n) 
void FindMissingNumbeRWithIndexBase(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int index = abs(arr[i]);
        if (arr[index - 1] > 0)
            arr[index - 1] *= -1; 
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            cout << "The Missing Element Is : " << i + 1 << endl;
    }      
}

void FindMissingNumbeRWithSortingAndSwaping(int arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        int index = arr[i] - 1;
        if (arr[i] != arr[index])
        {
            swap(arr[i], arr[index]);
        }
        else
            i++;
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << "The Missing Element Is : " << i + 1 << endl;
        } 
    }
    cout << endl;     
}



int main() 
{ 
    int size;
    cout << "Enter Size Of Array :" << endl;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array Element " << i << " : " << endl;
        cin >> arr[i];
    }

    FindMissingNumbeRWithSortingAndSwaping(arr, size);
    return 0; 
}