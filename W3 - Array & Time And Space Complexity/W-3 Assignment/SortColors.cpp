#include<iostream>
using namespace std; 
// This Question Methods
//1. Counting O(n)
//2. 2 pointer Approvh O(n) - In Palce Sort
//2. 3 Sorting Approvh O(nlogn)
void SortColorWith2Pointer(int arr[], int size)
{
    int index = 0;
    int left = 0;
    int right = size - 1;
    while (index <= right)
    {
        if (arr[index] == 2)
        {
            swap(arr[index], arr[right]);
            right--;
        }
        else if (arr[index] == 0)
        {
            swap(arr[index], arr[left]);
            left++;
            index++;
        }
        else
            index++;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " "; 
    }

}


int main() 
{ 
    int size;
    cout << "Enter Size Of Array : " << endl; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array Element : " << i << endl;
        cin >> arr[i];
    }

    SortColorWith2Pointer(arr, size);
    
    return 0; 
}

