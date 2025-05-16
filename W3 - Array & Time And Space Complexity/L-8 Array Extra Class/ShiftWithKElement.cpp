// THIS PROBLEM CODE BY MANY APROCH
// FIRST CREATE TEMPERARY ARRAY STORE KTH VALUE OF ARR THAN SHIF
// SCOEND APROCH IS SHIFTE HOLL ARRAY BY K TIME
// SCOEND APROCH IS WE CAN SOLVE WITH MODILO OPRATORE
// THERD APROCH IS WE CAN REVERSE VALUE FOR THREE TIME

#include <iostream>
using namespace std;

void RightShiftWithModulo(int arr[], int size, int k)
{
    int temp[size];

    // Shift with modulo
    for (int i = 0; i < size; i++) {
        int newindex = (i + k) % size;
        temp[newindex] = arr[i];
    }

    // Copy back to original array
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }

    // Print the array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    RightShiftWithModulo(arr, size, k);

    return 0;
}