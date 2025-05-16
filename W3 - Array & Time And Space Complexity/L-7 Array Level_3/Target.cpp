#include <iostream>
using namespace std;

bool FindTarget(int arr[][3], int r, int c, int target)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
        cout << endl;
    }
    return false;
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

    int target;
    cout << "Enter Target: " << endl;
    cin >> target;

    

    bool ans = FindTarget(arr, 3, 3, target);
    (ans) ? cout << "Target Found" << endl : cout << "Target Not Found" << endl;

    return 0;
}