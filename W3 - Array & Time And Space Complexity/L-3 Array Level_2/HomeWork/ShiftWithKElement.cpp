// THIS PROBLEM CODE BY MANY APROCH
// FIRST CREATE TEMPERARY ARRAY STORE KTH VALUE OF ARR THAN SHIF
// SCOEND APROCH IS SHIFTE HOLL ARRAY BY K TIME
// SCOEND APROCH IS WE CAN SOLVE WITH MODILO OPRATORE
// THERD APROCH IS WE CAN REVERSE VALUE FOR THREE TIME

#include <iostream>
using namespace std;

void RightShift(int arr[], int size, int k)
{
    // k = k % size; 
    int temp[k];
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[size - k + i];
    }

    for (int i = size - 1; i >= k; i--)
    {
        arr[i] = arr[i - k];
    }

    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
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
        cout << "Enter Element Of " << (i+1) << endl;
        cin >> arr[i];
    }

    int k;
    cout << "How Many Shift By : " << endl;
    cin >> k;
    RightShift(arr, size, k);

    return 0;
}