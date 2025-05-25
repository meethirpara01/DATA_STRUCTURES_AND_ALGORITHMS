#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

bool isPosibleSolution(vector<long long int> arr, long long int size, long long int need, long long int sol)
{
    long long int totalWood = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > sol)
            totalWood += arr[i] - sol;
    }
    return totalWood >= need;
}

int FindMaxHight(vector<long long int> arr, int size, int need)
{
    
    long long int start = 0;
    long long int end = *max_element(arr.begin(), arr.end());
    long long int ans = -1;

    while (start <= end)
    {
        long long int mid = (start + end) >> 1;
        if (isPosibleSolution(arr, size, need, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;  
    }
    return ans;
}

int main()
{
    long long int size;
    cout << "Enter Number Of Tree: ";
    cin >> size;

    vector<long long int> arr;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Hight(Meter) Of Tree " << i + 1 << ": ";
        long long int input;
        cin >> input;
        arr.push_back(input);
    }

    long long int need;
    cout << "How Many Meters Of Wood You Want: ";
    cin >> need;

    long long int ans = FindMaxHight(arr, size, need);
    cout << "Your Best Allocation Is With Maximum Height Of Machine Is: " << ans << endl;

    return 0;
}