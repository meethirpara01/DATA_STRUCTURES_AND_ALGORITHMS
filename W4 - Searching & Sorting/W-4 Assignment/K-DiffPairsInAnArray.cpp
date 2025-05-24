#include<iostream>
#include <set>
using namespace std; 
// TO SOLVE THIS QUESTION
// 1. BRUTE FORCE CHECK ALL PAIRS O(N^2)
// 2. TO POINTER APPROCH O(N)
// 3. BINARY SEARCH APPROCH O(N(log N))

int FindPairEqualK(int arr[], int size, int k)
{
    sort(arr, arr + size);
    int i = 0, j = 1;
    set<pair<int, int>> ans;

    while (i < size)
    {
        int diff = arr[j] - arr[i];
        if (i == j)
            j++;
        else if (diff == k)
        {
            ans.insert({arr[i], arr[j]});
            cout << arr[i] << " " << arr[j] << endl;
            i++, j++;
        }
        else if(diff > k)
            i++;
        else
            j++;
        
    }
    return ans.size();
}


int BS(int arr[], int size, int start, int target)
{
    int end = size;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
            end = mid - 1;    
    }
    return -1;
}

int FindPairs(int arr[], int size, int k)
{
    sort(arr, arr + size);
    set<pair<int, int>> ans;

    for (int i = 0; i < size; i++)
    {
        if (BS(arr, size, i + 1, arr[i] + k) != -1)
        {
            ans.insert({arr[i], arr[i] + k});
        }
        
    }
    return ans.size();
}

int main() 
{ 
    int size;
    cout << "Enter Size Of Array:" << endl; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i + 1 << " :" ;
        cin >> arr[i];
    }

    int k;
    cout << "Enter Diffrence:" << endl; 
    cin >> k;


    int ans = FindPairs(arr, size, k);
    cout << "Total Pair Is: "<< ans << endl; 
    
    return 0; 
}