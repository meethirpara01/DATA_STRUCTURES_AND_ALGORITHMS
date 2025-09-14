#include<iostream>
using namespace std; 

void printSubArray_util(vector<int>& nums, int start,  int end) 
{
    // BASE CASE
    if (end == nums.size())
    {
        return;
    }

    //PROCCESSING
    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    // RECURSIVE CALL
    printSubArray_util(nums, start, end + 1);
}

void printSubArray(vector<int>& nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        int end = start;
        printSubArray_util(nums, start, end);
    }
}

int main() 
{ 
    int size;
    cout << "Enter An Size Of Array: "; 
    cin >> size;

    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i + 1 << " Of Array: ";
        cin >> nums[i];
    }

    printSubArray(nums);
    return 0; 
}