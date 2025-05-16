// WE CAN SOLVE THIS QUESTION WITH COUNTING IT'S BRUTE FORCE METHOD
// AND SECONG METHOD IS 2 POINTER APPROCH 
// THRED METHOD IS SORT PRE DIFINE FUNCTION

#include <iostream>
using namespace std;

void Sort0sAnd1sM2(int arr[], int size)
{
    int i = 0;
    int j = 0;

    while (j < size)
    {
        if (arr[j] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }

    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    } 
}

void Sort0sAnd1sM1(int arr[], int size)
{
    int count0 = 0;
    int count1 = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            count0++;
        if (arr[i] == 1)
            count1++;
    }

    int i;
    // for (i = 0; i < count0; i++)
    // {
    //     arr[i] = 0;
    // }
    
    // for (int j = i; j < size; j++)
    // {
    //     arr[j] = 1;
    // }
    while (count0--)
    {
        arr[i] = 0;
        i++;
    }
    while (count1--)
    {
        arr[i] = 1;
        i++;
    }
    
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
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
    Sort0sAnd1sM2(arr, size);

    return 0;
}