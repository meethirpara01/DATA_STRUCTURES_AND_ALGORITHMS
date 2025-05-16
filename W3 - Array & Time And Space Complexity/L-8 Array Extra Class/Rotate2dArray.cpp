#include <iostream>
#include <vector>
using namespace std;
// First Of All Transpose The Array And Reverse The Row 1 And 3

void Rreverse(vector<int>& arr)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void RotateArray(vector<vector<int>>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr[i].size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        Rreverse(arr[i]);
        // reverse(arr[i].begin(), arr[i].end()); 
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    vector<vector<int>> arr(3, vector<int>(3, 0));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << "Enter Element [" << i << "][" << j << "]" << endl;
            cin >> arr[i][j];
        }
    }

    cout << "Your Array Looks Like This : " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Rotated Array :" << endl;
    RotateArray(arr);
    
    return 0;
}