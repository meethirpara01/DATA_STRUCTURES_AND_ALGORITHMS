#include <iostream>
using namespace std;
// This Question Methods
// 1. Using Brute Force - Loop O(n^2)
// 2. With Two Temp Array O(n) But Space Complexity Incrise This Mehod Is Called As PreFix

void findPivotBruteForce(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int lsum = 0;
        int rsum = 0;
        for (int j = 0; j < i; j++)
            lsum += arr[j];

        for (int j = i + 1; j < arr.size(); j++)
            rsum += arr[j];

        if (lsum == rsum)
            cout << arr[i] << " Is The Pivot Element " << "And Their Index Is " << i << endl;
        else
            cout << "-1" << endl;
    }
}

void findPivotTwoTempArray(vector<int> &arr)
{
    vector<int> lsum(arr.size(), 0);
    vector<int> rsum(arr.size(), 0);

    for (int i = 1; i < lsum.size(); i++)
        lsum[i] = lsum[i - 1] + arr[i - 1];

    for (int i = rsum.size() - 2; i >= 0; i--)
        rsum[i] = rsum[i + 1] + arr[i + 1];

    for (int i = 0; i < arr.size(); i++)
    {
        if (lsum[i] == rsum[i])
            cout << arr[i] << " Is The Pivot Element " << "And Their Index Is " << i << endl;  
        else
            cout << "-1" << endl;
    }
}

int main()
{

    int size;
    cout << "Enter Size Of Array: ";
    cin >> size;

    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
        int element = 0;
        cout << "Enter Array Element : " << i << endl;
        cin >> element;
        arr.push_back(element);
    }

    findPivotTwoTempArray(arr);

    return 0;
}
