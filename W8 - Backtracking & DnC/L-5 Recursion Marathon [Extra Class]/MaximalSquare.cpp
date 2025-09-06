#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int& maxi)
{
    // BASE CASE
    if (i >= row || j >= col)
    {
        return 0;
    }

    // EXPLORE ALL 3 POSIBLE WAYS
    int right = solve(matrix, i, j + 1, row, col, maxi);
    int diagnol = solve(matrix, i + 1, j + 1, row, col, maxi);
    int down = solve(matrix, i + 1, j, row, col, maxi);

    // CHECK CAN WE BUILD SQAURE FROM CURRENT POSITION
    if (matrix[i][j] == '1')
    {
        int ans = 1 + min(right, min(diagnol, down));
        // CATCH BEACUSE WE NEED TO FIND LARGEST SQUARE
        maxi = max(maxi, ans);
        return ans; 
    }
    else
    {
        // IF CURRENTE POSITION IS 0 THAT ANSWER WILL BE ALSO 0
        return 0;
    }
}

int maximalSquare(vector<vector<char>>& matrix)
{
    int i = 0;
    int j = 0;

    int row = matrix.size();
    int col = matrix[0].size();

    int maxi = 0;

    int ans = solve(matrix, i, j, row, col, maxi);
    return maxi * maxi;
}

int main()
{
    int row, col;
    cout << "Enter Number Of Rows: ";
    cin >> row;

    cout << "Enter Number Of Columns: ";
    cin >> col;

    vector<vector<char>> matrix(row, vector<char>(col));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter Matrix Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    int finalAns = maximalSquare(matrix);
    cout << "Maximal Square In This Matrix IS: " << finalAns << endl;

    return 0;
}
