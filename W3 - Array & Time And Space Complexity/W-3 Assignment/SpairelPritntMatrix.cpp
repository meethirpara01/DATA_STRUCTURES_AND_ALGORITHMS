#include<iostream>
using namespace std; 
 
void SpirelPrintMatrix(vector<vector<int>> arr)
{
    vector<int> ans;
    int row = arr.size();
    int col = arr[0].size();

    int total_element = row * col;

    int startingrow = 0;
    int endingcol = col - 1;
    int endingrow = row - 1;
    int startingcol = 0;

    int count = 0;
    while (count < total_element)
    {
        for (int i = startingcol; i <= endingcol && count < total_element; i++)
        {
            ans.push_back(arr[startingrow][i]);
            count++;
        }
        startingrow++;

        for (int i = startingrow; i <= endingrow && count < total_element; i++)
        {
            ans.push_back(arr[i][endingcol]);
            count++;
        }
        endingcol--;

        for (int i = endingcol; i >= startingcol && count < total_element; i--)
        {
            ans.push_back(arr[endingrow][i]);
            count++;
        }
        endingrow--;

        for (int i = endingrow; i >= startingrow && count < total_element; i--)
        {
            ans.push_back(arr[i][startingcol]);
            count++;
        }
        startingcol++;
    }
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main() 
{ 
    vector<vector<int>> arr
    {
        {1,2,3,4},
        {5,5,7,8},
        {9,10,11,12},
        {13,14,15,16},
        {17,18,19,20}
    };

    SpirelPrintMatrix(arr);
    return 0; 
}