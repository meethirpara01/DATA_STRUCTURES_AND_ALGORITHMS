// Debug the code. Find the length of the longest strictly increasing subsequence.
#include <iostream>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin(); // Before solving get acquainted with lower_bound()
            ans[index] = nums[i];
        }
    }
    return ans.size();
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

    int ans = lengthOfLIS(arr);
    cout << "LEANGHT IS: " << ans << endl;

    return 0;
}