#include <iostream>
#include<queue>
using namespace std;

class Info
{
    public:
        int data;
        int rowIndex;
        int colIndex;

        Info(int data, int rowIndex, int colIndex)
        {
            this->data = data;
            this->rowIndex = rowIndex;
            this->colIndex = colIndex;
        }
};

class compare
{
    public:
        bool operator()(Info* a, Info* b)
        {
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int size, int noOfArray) 
{
    priority_queue<Info*, vector<Info*>, compare> pq;
    int maxi = INT_MIN;
    int mini = INT_MAX;

    // STEP 1 :- PROCESS FIRST K ELEMENTS
    for (int row = 0; row < noOfArray; row++)
    {
        int element = arr[row][0];
        Info* temp = new Info(element, row, 0);
        pq.push(temp);
        maxi = max(maxi, element);
        mini = min(mini, element);
    }

    int ansStart = mini;
    int ansEnd = maxi;

    while (!pq.empty())
    {
        Info* front = pq.top();
        pq.pop();
        int topdata = front->data;
        int topRow = front->rowIndex;
        int topCol = front->colIndex;

        mini = topdata;
        // MAXI KI VALUE PEHLEE SE PADI HUI H
        // COMPARE KARLETE H FOR SMALLER RANGE
        if ((maxi - mini) < (ansEnd - ansStart)) // MOST IMPOETENT
        {
            // UPDATE THE ANSWEER
            ansStart = mini;
            ansEnd = maxi;
        }

        // INSERTION WALA PART
        if (topCol + 1 < arr[topRow].size())
        {
            int newElement = arr[topRow][topCol + 1];
            maxi = max(maxi, newElement); // CATCH
            Info* newInfo = new Info(newElement, topRow, topCol + 1);
            pq.push(newInfo);
        }
        else
        {
            // YOU TRAVERSE ON HOLE ARRAY - AGGGE KIO ELEMENT NAHI HAI PUSH KARNE KO
            break;
        }
    }

    vector<int> ans;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);
    return ans;
}

int main()
{
    // int k;
    // cout << "ENTER NUMBER OF ARRAY: ";
    // cin >> k;

    // int size;
    // cout << "ENTER SIZE OF ARRAY: ";
    // cin >> size;

    // int arr[k][size];
    // for (int row = 0; row < k; row++)
    // {
    //     for (int col = 0; col < size; col++)
    //     {
    //         cout << "ENTER ELEMENT " << "[" << row + 1 << "]" << "[" << col + 1 << "] OF ARRAY: ";
    //         cin >> arr[row][col]; 
    //     }
    // }
    int size = 4;
    int k = 3;

    vector<vector<int>> arr = {
        {1, 4, 8, 11},
        {2, 3, 6, 10},
        {5, 7, 12, 14},
    };

    vector<int> ans;
    ans = mergeKSortedArrays(arr, size, k);

    cout << "PRINTING SMALLEST RANGE IN K-LIST: " << endl;
    for(auto elem : ans)
    {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}