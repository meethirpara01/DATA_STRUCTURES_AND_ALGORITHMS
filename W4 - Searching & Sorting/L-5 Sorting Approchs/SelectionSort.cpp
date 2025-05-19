#include<iostream>
using namespace std; 
 
void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                minIndex = j;
            }
        } 
        swap(arr[i], arr[minIndex]);
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

    SelectionSort(arr, size);
    return 0; 
}