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

void mergeKSortedArrays(int arr[][4], int size, int noOfArray, vector<int> &ans) 
{
    priority_queue<Info*, vector<Info*>, compare> pq;

    // STEP 1 :- PROCESS FIRST K ELEMENTS
    for (int row = 0; row < noOfArray; row++)
    {
        int element = arr[row][0];
        Info* temp = new Info(element, row, 0);
        pq.push(temp);
    }

    while (!pq.empty())
    {
        Info* front = pq.top();
        pq.pop();
        int topdata = front->data;
        int topRow = front->rowIndex;
        int topCol = front->colIndex;

        // SRORE ANSWER IN ANS VECTOR
        ans.push_back(topdata);

        // NEXT ELEMENT FOR THE SAME ROW, JISME SE POP KIA HAI JUST ABHI
        if (topCol + 1 < size)
        {
            // IT MEANS THEIR ARE STILL ELEMENT PRESENET IN THE ROW
            Info* NewInsert = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
            pq.push(NewInsert);
        }
    } 
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
    int arr[3][4] = {
        {1, 4, 8, 11},
        {2, 3, 6, 10},
        {5, 7, 12, 14},
    };
    int size = 4;
    int k = 3;

    vector<int> ans;
    mergeKSortedArrays(arr, size, k, ans);

    cout << "PRINTING MERGE SINGLE SORTED ARRAY: " << endl;
    for(auto elem : ans)
    {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}