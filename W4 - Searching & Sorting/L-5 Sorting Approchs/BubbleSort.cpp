#include<iostream>
using namespace std; 
 
void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        } 
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

    BubbleSort(arr, size);
    return 0; 
}