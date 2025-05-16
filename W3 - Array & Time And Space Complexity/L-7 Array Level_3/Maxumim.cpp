#include <iostream>
#include <limits>
using namespace std;

int FindMaximum(int arr[][3], int r, int c)
{   int max = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
        cout << endl;
    }
    return max;
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

    
    int ans = FindMaximum(arr, 3, 3);
    cout << "Maximum Value In This Array :" << ans << endl;
    return 0;
}