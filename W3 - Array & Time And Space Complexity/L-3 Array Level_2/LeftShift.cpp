#include <iostream>
using namespace std;

void LeftShift(int arr[], int size)
{
    int temp = arr[0];
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[size - 1] = temp;

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
        cout << "Enter Element Of " << (i+1) << endl;
        cin >> arr[i];
    }
    LeftShift(arr, size);

    return 0;
}