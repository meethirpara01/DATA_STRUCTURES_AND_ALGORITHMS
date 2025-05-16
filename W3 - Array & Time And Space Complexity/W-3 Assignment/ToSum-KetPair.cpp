#include<iostream>
using namespace std; 
// This Question Methods
//1. Using Nested Loop O(n^2)
//2. Using Two Pointer Approch O(n log n)
void ToSum(int arr[], int size, int Target)
{
    int Ii = -1, Ij = -1;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == Target)
            {
                Ii = i;
                Ij = j;
            }
        }
    }

    cout << "BothIndex Is :" << Ii << ", " << Ij << endl;  
}


void ToSumWith2Pointer(int arr[], int size, int Target)
{
    sort(arr, arr + size);
    int start = 0;
    int end = size - 1;
    int Ii = -1, Ij = -1;

    while (start < end)
    {
        if (arr[start] + arr[end] == Target)
        {
            Ii = start;
            Ij = end;
            break;
        }
        else if (arr[start] + arr[end] > Target)
        {
            end--;
        }
        else
        {
            start++;
        }
    }

    cout << "BothIndex Is :" << Ii << ", " << Ij << endl;  
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

    int Target;
    cout << "Enter Target Value: " << endl; 
    cin >> Target;

    ToSumWith2Pointer(arr, size, Target);
    
    return 0; 
}

