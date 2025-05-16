#include <iostream>
#include <limits>
using namespace std;

void TransePose(int arr[][3], int r, int c)
{  
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int j = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = i; j < c; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }  
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
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

    TransePose(arr, 3, 3);

    

    return 0;
}