#include<iostream>
using namespace std; 

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = end;
    int i = start - 1;
    int j = start;

    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
    
    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}

int main() 
{ 
    int size;
    cout << "Enter Size Of Size: " << endl; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter" << i + 1 << " Element Of Array: ";
        cin >> arr[i];
    }

    quickSort(arr, 0, size - 1);

    cout << "AFTER QUICK SORT: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0; 
}