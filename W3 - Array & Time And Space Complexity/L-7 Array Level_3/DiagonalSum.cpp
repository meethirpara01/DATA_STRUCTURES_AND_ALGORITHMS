#include <iostream>
#include <limits>
using namespace std;

void DiagonalSum(int arr[][3], int r, int c)
{  
    int sum = 0; 
    for (int i = 0; i < r; i++)
    {
        sum += arr[i][i];
    }
    cout << "Diagonal Sum Is : " << sum << endl;
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

    DiagonalSum(arr, 3, 3);

    return 0;
}