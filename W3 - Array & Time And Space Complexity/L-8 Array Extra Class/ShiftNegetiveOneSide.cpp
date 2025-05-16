// This Question Approches
// 1. Sorting (log n)
// 2. 2 Pointer (n)
// 3. Temp Array (n)

#include<iostream>
using namespace std; 

void ShiftNegetiveOneSizeM1(int arr[], int size)
{
    int i = 0;
    int j = 0;
    while (j < size)
    {
        if(arr[j] < 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void ShiftNegetiveOneSizeM2(int arr[], int size)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        while (arr[i] < 0)
        {
            i++;
        }

        while (arr[j] > 0)
        {
            j--;
        }
        
        if(arr[j] < 0)
        {
            swap(arr[i], arr[j]);
            j--;
            i++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
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

    ShiftNegetiveOneSizeM2(arr, size);
    
    return 0; 
}