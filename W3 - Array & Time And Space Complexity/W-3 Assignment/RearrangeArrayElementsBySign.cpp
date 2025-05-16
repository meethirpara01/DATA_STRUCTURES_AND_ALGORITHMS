#include <iostream>
using namespace std;
// Aproch to Solve This Question
// 1. Extra Space mack 2 array pos and neg than add element in new ans array
// 2. 2 Pointer 
vector<int> rearrangeArrayWith2Pointer(vector<int> &nums)
{
    // Method 2. Two pointer
    vector<int> ans(nums.size(), -1);
    int odd = 1, even = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];
        if (num > 0)
        {
            ans[even] = num;
            even += 2;
        }
        else
        {
            ans[odd] = num;
            odd += 2;
        }
    }
    return ans;
}

vector<int> rearrangeArrayWithBruteForce(vector<int> &nums)
{
    // Method 1. Brute Force with Temp Array
    vector<int>pos, neg;
    for(int i=0;i<nums.size();i++){
        if(nums[i] < 0)
            neg.push_back(nums[i]);
        else
            pos.push_back(nums[i]);
    }
    vector<int>ans;
    int i=0;
    while(i < pos.size()){
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
        i++;
    }
    return ans;
}

int main()
{
    int size;
    cout << "Enter Size of Array :" << endl;
    cin >> size;

    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array Element " << i + 1 << " :" << endl;
        cin >> arr[i];
    }

    vector<int> ans =  rearrangeArrayWith2Pointer(arr);

    for (int elem : ans)
    {
        cout << elem << " " ;
    }
    
    return 0;
}
