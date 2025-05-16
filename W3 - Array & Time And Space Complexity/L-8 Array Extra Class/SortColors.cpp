// This Question Approches
// 1. Counting (n)
// 2. 2 Pointer (n)
// 3. Sorting (nlog n)

#include<iostream>
using namespace std; 

void SortColors(int arr[], int size)
{
    int index = 0;
    int left = 0;
    int right = size - 1;

    while (index <= right)
    {
        if (arr[index] == 0)
        {
            swap(arr[index], arr[left]);
            left++;
            index++;
        }
        else if (arr[index] == 2)
        {
            swap(arr[index], arr[right]);
            right--;
            // HERE IS CATCH DO NOT index++ BECUSE THE SWAP ELEMENTE IS WHICH WE DON'T KNOW
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
    cout << "Enter Size Of Array :" << endl;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array Element " << i << " : " << endl;
        cin >> arr[i];
    }

    SortColors(arr, size);
    
    return 0; 
}