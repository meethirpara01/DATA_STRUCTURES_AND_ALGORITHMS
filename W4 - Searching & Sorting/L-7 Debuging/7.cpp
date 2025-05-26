// Debug the code.
#include <iostream>
using namespace std;
int binarySearch(vector<int> &nums, int target)
{
    int left = 0, right = int(nums.size());

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
        {
            left = mid + 1; // HERE CHANGE
        }
        else
        {
            right = mid;
        }
    }

    if (left >= 0 and nums[left - 1] == target) // HERE CHANGE
    {
        return left;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int size;
    cout << "Enter Size Of Array :" << endl;
    cin >> size;

    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
        cout << " Enter " << i + 1 << " Element : ";
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int target;
    cout << "Enter Size Of Array :" << endl;
    cin >> target;

    int ans = binarySearch(arr, target);
    cout << "Target Is: " << ans << endl;

    return 0;
}