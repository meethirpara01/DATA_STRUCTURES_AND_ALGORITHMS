// Code by Lakshay Bhaiya, Please Dry Run to Understand
// Dry Run on Example 1: nums = [10,20,50,40,30]
// Dry Run on Example 2: nums = [10,20,30,90,70,60,50,40]
#include<iostream>
using namespace std; 

int peakIndexInMountainArray(vector<int>& a) {
        int ans = -1;
        int start = 0;
        int end = a.size() - 1;

        while(start <= end){
            int mid = (start + end) / 2;
            if(a[mid + 1] > a[mid]){
                start = mid + 1;
            }
            else if(a[mid - 1] > a[mid]){
                end = mid - 1;
            }
            else {
                // It must be Peak
                ans = mid;
                break;
            }
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

    int ans =  peakIndexInMountainArray(arr);

    
}

