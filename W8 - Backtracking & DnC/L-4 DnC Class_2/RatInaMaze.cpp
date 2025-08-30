#include <iostream>
using namespace std;

// A FUNCTION THAT WILL HANDEL ALL THE BELOW MENTIONED POSSIBILITIESL:
// POSSIBLITYS
        // PATH CLOSED
        // IF OUT BOUND
        // CHECH IS POSITION IS ALREDY VISITED
bool isSafe(int maze[][4], int srcx, int srcy, int newx, int newy, int row, int col, vector<vector<bool>> &visited)
{
    if ((newx >= 0 && newx < row) && (newy >= 0 && newy < col) && maze[newx][newy] == 1 && visited[newx][newy] == false)
    {
        
    }
}

void PrintAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output, vector<vector<bool>> &visited)
{
    // BASE CASE
    // DESTINATION COORDINATES ARE [ROW - 1], [COL - 1]
    if (srcx == row - 1 && srcy == col - 1)
    {
        // REACHED DESTIONATION
        cout << output << endl;
        return;
    }


    // SOLVE ONLY CASE ONE AND RECURSION WILL SEE

    // UP
    // POSSIBLITYS
        // PATH CLOSED
        // IF OUT BOUND
        // CHECH IS POSITION IS ALREDY VISITED
    if (isSafe())
    {
        // NOW MARK VISITED
        // RECURSIVE CALL
        // BACKTRACKING
    }
    

    // RIGHT
    if (isSafe())
    {
        // NOW MARK VISITED
        // RECURSIVE CALL
        // BACKTRACKING
    }

    // DOWN
    if (isSafe())
    {
        // NOW MARK VISITED
        // RECURSIVE CALL
        // BACKTRACKING
    }

    //LEFT
    if (isSafe())
    {
        // NOW MARK VISITED
        // RECURSIVE CALL
        // BACKTRACKING
    }
    

}
int main()
{
    int row;
    cout << "Enter Total Row Of Array: ";
    cin >> row;
    
    int col;
    cout << "Enter Total Col Of Array: ";
    cin >> col;

    int maze[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter Array Element " << "[" << i + 1 << "]" << "[" << j + 1 << "]" << ": ";
            cin >> maze[i][j];
        }
    }

    int srcx = 0;
    int srcy = 0;

    string output = "";

    // CREATE VISITED 2D ARRAY
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    if (maze[0][0] == 0)
    {
        // SORCE POSITION IS CLOSED, THAT MEAN RAT CAN NOT MOVE
        cout << "NO PATH EXISTS!" << endl;
        return 0;
    }
    else
    {
        visited[srcx][srcy] = true;
        PrintAllPath(maze, row, col, srcx, srcy, output, visited);
    }
        
    return 0;
}