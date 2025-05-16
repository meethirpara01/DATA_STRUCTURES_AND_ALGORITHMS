#include<iostream>
using namespace std; 
 
void WavePrintMatrix(vector<vector<int>> arr)
{
    int row = arr.size();
    int col = arr[0].size();

    for (int i = 0; i < col; i++)
    {
        if ((i & 1) == 0)
        {
            for (int j = 0; j < row; j++)
            {
                cout << arr[j][i] << " ";
            }   
        }
        else
        {
            for (int j = row - 1; j >= 0; j--)
            {
                cout << arr[j][i] << " ";
            } 
        }
        
        
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

    WavePrintMatrix(arr);
    return 0; 
}