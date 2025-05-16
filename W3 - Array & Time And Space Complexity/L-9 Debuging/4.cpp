

#include<iostream>
using namespace std;

void swapAlternate(int arr[],int size){
    for(int i=0;i<size-1;i=i+2){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " ;
    }
}

int main()
{
    int size;
    cout << "Enter Size Of Array (n-1): ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << (i + 1) << ": ";
        cin >> arr[i];
    }

    swapAlternate(arr, size);

    return 0;
}

// Here Is Mistake In Swapung