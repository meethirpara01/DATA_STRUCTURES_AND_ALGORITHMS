#include <iostream>
#include <vector>
using namespace std;
// TIME COMPLEXITY O(2^log(m -1))  Here m = i;
int BinarySearch(vector<int> &arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return -1;
}

int ExponetialSearch(vector<int> &arr, int size, int target)
{
    if (arr[0] == target)
        return 0;
    int i = 1;
    while (i < size && arr[i] <= target)
    {
        i = i * 2;
    }
    return BinarySearch(arr, i / 2, min(i, size - 1), target);
}



int main()
{
    int size;
    cout << "Enter Size Of Array:" << endl;
    cin >> size;

    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i + 1 << " :";
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int target;
    cout << "Enter Target:" << endl;
    cin >> target;

    int ans = ExponetialSearch(arr, size, target);
    cout << "Your Target Is:"<< arr[ans] << endl;
    
    return 0;
}