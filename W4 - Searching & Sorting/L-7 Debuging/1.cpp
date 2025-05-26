//1. Debug the code. Search in sorted rotated array. (Sorting was less to high).
#include <iostream>
using namespace std;

int search(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[l] <= nums[mid])
        {
            if (nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1; // No need to debug this line.
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
    cout << "Enter Target :" << endl;
    cin >> target;

    int ans = search(arr, target);
    (ans != -1) ? cout << "Target Found" << endl : cout << "Target Not Found" << endl;

    return 0;
}


// Wrong Condition in This line  // else if (nums[l] >= nums[mid])