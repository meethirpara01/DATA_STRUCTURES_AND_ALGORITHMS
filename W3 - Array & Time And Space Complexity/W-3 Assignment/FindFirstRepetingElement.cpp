#include<iostream>
using namespace std; 
// This Question Approches
// 1. Brute Forece Nested Loops O(n^2)
// 2. Hashing T.C. = O(n) S.C. = O(n)

void FindduplicareFirstOccrenceWithHash(int arr[], int size)
{
    unordered_map<int, int>hash;
    for (int i = 0; i < size; i++)
        hash[arr[i]]++;
    
    for (int i = 0; i < size; i++)
    {
        if (hash[arr[i]] > 1)
        {
            cout << "Your Duplicate First Ocrrence Is : " << i + 1 << endl;
            break;
        }  
    }    
}

void UserDefineHash(int arr[], int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        } 
    }
    
    int hash[max];

    for (int i = 0; i < max; i++)
        hash[arr[i]]++;
    
    for (int i = 0; i < size; i++)
    {
        if (hash[arr[i]] > 1)
        {
            cout << "Your Duplicate First Ocrrence Is : " << i + 1 << endl;
            break;
        }  
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

    UserDefineHash(arr, size);
    return 0; 
}