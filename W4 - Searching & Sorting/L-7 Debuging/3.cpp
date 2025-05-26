// Debug the code. Find minimum in rotated sorted array. (Sorting was in ascending order).
#include <iostream>
using namespace std;

int findMin(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1, ans = start;
    while (nums[start] > nums[end])
    {
        int mid = (start + end) >> 1;
        if (nums[mid] <= nums[start] && nums[mid] <= nums[end])
            end = mid;
        else if (nums[mid] >= nums[start] && nums[mid] >= nums[end])
            start = mid + 1;
        else
            return nums[mid];
        ans = start;
    }
    return nums[ans];
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

    int ans = findMin(arr);
    cout << "Minmum Value Is: " << ans << endl;

    return 0;
}


// I'L CHANHE IN SHIFTING START = MID AND END = NUMS.SIZE() AND THAN DONE.