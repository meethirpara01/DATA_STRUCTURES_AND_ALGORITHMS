#include <iostream>
using namespace std;

void PrintPair(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "(" << arr[i]<< "," << arr[j] << ")" << endl;
        }
        cout << endl;
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
    PrintPair(arr, size);

    return 0;
}