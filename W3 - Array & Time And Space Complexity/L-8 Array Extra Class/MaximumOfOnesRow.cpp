#include <iostream>
#include <vector>
using namespace std;
// Using Counting

void CountMaxOneInRow(vector<vector<int>> arr)
{
    int OneCount = INT_MIN;
    int RowNo = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
        }

        if (OneCount < count)
        {
            OneCount = count;
            RowNo = i;
        }
    }

    cout << "Maximum One's In Row " << OneCount << " And Their Index IS " << RowNo << endl;
}

int main()
{
    vector<vector<int>> arr(3, vector<int>(4, 0));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << "Enter Element [" << i << "][" << j << "]" << endl;
            cin >> arr[i][j];
        }
    }

    CountMaxOneInRow(arr);

    return 0;
}