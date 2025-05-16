#include<iostream>
using namespace std; 
// This Question Approches
// 1. Sorting and currente element is same with their next element O(n logn)
// 2. Index Base Negetive Marking Method But We Modify The Array O(n) 
// 3. Positing Methos Set Array Element With Their Index BOth Are Same But We Modify The Array O(n)
void FindDuplicatesWithSorting(int arr[], int size)
{
    sort(arr, arr + size);

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i+1])
        {
            cout << arr[i] << " Is Duplicate Number " << endl;
        }
    }
    cout << "Dose Not Exist Duplicate Number " << endl;
}

void FindDuplicatesWithNegetiveMarking(int arr[], int size)
{
    int ans  = -1;

    for (int i = 0; i < size; i++)
    {
        int index = abs(arr[i]);
        if (arr[index] < 0)
        {
            cout << index << " Is Duplicate Number " << endl;
        }
        arr[index] *= -1;
    }
}

void FindDuplicatesWithPositing(int arr[], int size)
{
    while (arr[0] != arr[arr[0]])
    {
        swap(arr[0], arr[arr[0]]);
    }
    cout << arr[0] << " Is Duplicate Number " << endl;
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

    FindDuplicatesWithPositing(arr, size);
    return 0; 
}