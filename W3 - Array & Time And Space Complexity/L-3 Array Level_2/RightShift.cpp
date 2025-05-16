#include <iostream>
using namespace std;

void RightShift(int arr[], int size)
{
    int temp = arr[size - 1];
    for (int i = size - 1; i >= 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

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
    RightShift(arr, size);

    return 0;
}