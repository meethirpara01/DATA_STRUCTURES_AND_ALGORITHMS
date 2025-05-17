#include<iostream>
#include<vector>
using namespace std; 

bool FindTarget(vector<vector<int>>& arr, int target)
{
    int row = arr.size();
    int col = arr[0].size();
    int totalSS = row * col;

    int start = 0;
    int end = totalSS - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int rowIndex = mid / col;
        int colIndex = mid % col;
        int currNumber = arr[rowIndex][colIndex];

        if (currNumber == target)
            return true;
        else if (currNumber < target)
            start = mid + 1;
        else 
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return false;
}

int main() 
{
    int row;
    cout << "Enter Number Of Row:" << endl; 
    cin >> row;

    int col;
    cout << "Enter Number Of Col:" << endl; 
    cin >> col;

    vector<vector<int>> arr(row, vector<int>(col));;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter Elemnt: arr" << "[" << i << "]" << "[" << j << "]" << "";
            cin >> arr[i][j];
        } 
    }

    int target;
    cout << "Enter target:" << endl; 
    cin >> target;
    

    bool ans = FindTarget(arr, target);

    (ans) ? cout << "Target Found!!!" << endl : cout << "Target Not Found!!!" << endl;
    
    return 0; 
}