#include <iostream>
#include <queue>
using namespace std;

void solveForMedian(double &median, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int element)
{
    if (maxi.size() == mini.size())
    {
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else 
        {
            maxi.push(element);
            median = maxi.top();
        }
    }
    else if (maxi.size() == mini.size() + 1)
    {
        if (element > median)
        {
            mini.push(element);
        }
        else
        {
            int maxTop = maxi.top();
            maxi.pop();
            mini.push(maxTop);
            maxi.push(element);
        }
        median = (mini.top() + maxi.top()) / 2.0;
    }
    else if (mini.size() == maxi.size() + 1)
    {
        if (element > median)
        {
            int minTop = mini.top();
            mini.pop();
            maxi.push(minTop);
            mini.push(element);
        }
        else
        {
            maxi.push(element);
        }
        median = (mini.top() + maxi.top()) / 2.0;
    }   
}

int main()
{
    // int size;
    // cout << "ENTER SIZE OF ARRAY: ";
    // cin >> size;

    vector<int> arr = {12, 10, 8, 4, 2, 3, 15};
    int size = 7;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "ENTER ELEMENT " << "[" << i + 1  << "] OF ARRAY: ";
    //     cin >> arr[i]; 
    // }

    double median = 0;
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    for (int i = 0; i < size; i++)
    {
        int element = arr[i];
        solveForMedian(median, maxi, mini, element);
        cout << "MEDIAN FOUND: " << median << endl;
    }
    return 0;
}