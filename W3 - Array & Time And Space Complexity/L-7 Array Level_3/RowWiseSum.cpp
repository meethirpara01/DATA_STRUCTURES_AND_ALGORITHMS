#include <iostream>
#include <limits>
using namespace std;

void RowWiseSum(int arr[][3], int r, int c)
{   
    for (int i = 0; i < r; i++)
    {
        int sum = 0;
        for (int j = 0; j < c; j++)
        {
            sum += arr[i][j];
        }
        cout << "Sum Of" << i << "Is :" << sum << endl;
    }
}

int main()
{
    int arr[3][3]; 
    cout << "Enter Array Elemnet:" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter Element arr[" << i << "]" << "[" << j << "] "; 
            cin >> arr[i][j];
        }
        cout << endl;
    }

    
    RowWiseSum(arr, 3, 3);
    return 0;
}