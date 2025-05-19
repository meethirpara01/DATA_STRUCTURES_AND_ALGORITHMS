#include<iostream>
using namespace std; 
 
void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+ 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int main() 
{ 
    int size;
    cout << "Enter size of Array :" << endl; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << " Enter " << i + 1 << " Element : " ;
        cin >> arr[i];
    }

    InsertionSort(arr, size);
    return 0; 
}