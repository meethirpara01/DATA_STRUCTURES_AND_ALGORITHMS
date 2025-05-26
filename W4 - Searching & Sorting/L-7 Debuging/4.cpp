// Debug the code. A peak element is an element that is strictly greater than its neighbors. Find the peak element.
#include <iostream>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = (low + high) >> 1;
        if (nums[mid] >= nums[mid + 1])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
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

    int ans = findPeakElement(arr);
    cout << "Minmum Value Is: " << arr[ans] << endl;

    return 0;
}

// IN THIS CODE PROBLEM IN SHIFTING AND RETURN VALUE AND START = MID I'L CHANGE ALL AND DONE.