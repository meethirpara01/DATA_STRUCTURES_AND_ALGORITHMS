// 3. Debug the code. Your task is to populate the array using the integer values in the range 1 to N (both inclusive) in the order - 1,3,5,.......,6,4,2.

#include<iostream>
using namespace std;

void populate(int arr[],int n){
    int j=0;
    for(int i=0; i < n; i = i + 2){
        arr[n-j - 1] = i+2;
        arr[j] = i+1;
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " " ;
    }
}

int main()
{
    int n;
    cout << "Enter Size Of Array: ";
    cin >> n;

    int arr[n];

    populate(arr, n);

    return 0;
}

// In Even Vlaue Array Out Of Bound 
