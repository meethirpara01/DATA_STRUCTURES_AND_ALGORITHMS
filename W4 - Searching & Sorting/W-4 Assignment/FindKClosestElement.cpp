// MOST IMP
#include <iostream>
#include <vector>
using namespace std;
// TO SOLVE THIS QUESTION
// 1. BRUTE FORCE SORT BU DIFFRENCE AND ANS WILL BE FIEST Kth ELEMENT O(n)
// 2. TO POINTER APPROCH O(N - K)
// 2. BINARY SEARCH APPROCH O(log N)
// IMPORTENT TEST CASE::
// 1. arr = [1, 2, 3, 4, 5] x = 3, k = 4
// 1. arr = [1, 2, 3, 4, 5] x = -1, k = 4
// 1. arr = [1, 2, 3, 4, 5] x = 6, k = 2
// 1. arr = [3, 5, 8, 10] x = 15, k = 2

vector<int> FindCloserElementWithToPtr(vector<int> &arr, int size, int x, int k)
{
    int left = 0;
    int right = size - 1;

    while (right - left >= k)
    {
        if (abs(x - arr[left]) > abs(x - arr[right]))
            left++;
        else
            right--;
    }

    // vector<int> ans;
    // for (int i = left; i < right; i++)
    // {
    //     ans.push_back(arrr[i]);
    // }

    return vector<int>(arr.begin() + left, arr.begin() + right + 1);
}

int LowerBound(vector<int> &arr, int x)
{
    int start = 0;
    int end = arr.size() - 1;
    int ans = end;  // CATCH

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            end = mid - 1;
        }
        // else if (x > arr[mid])
        // {
        //     start = mid + 1;
        // }
        else
            start = mid + 1;
    }
    return ans;
}
vector<int> FindCloserElementWithBinarySearch(vector<int> &arr, int size, int x, int k)
{

    int right = LowerBound(arr, x);
    int left = right - 1;

    while (k--)
    {
        if (left < 0) // CATCH
            right++;
        else if (right >= arr.size()) // CATCH
            left--;
        else if (abs(x - arr[left]) > abs(arr[right] - x))
            right++;
        else
            left--;
    }
    return vector<int>(arr.begin() + left + 1, arr.begin() + right); // CATCH
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

    int x;
    cout << "Enter Element To Find Their Colser Elements:" << endl;
    cin >> x;

    int k;
    cout << "Enter Number Of Closest Element:" << endl;
    cin >> k;

    vector<int> ans = FindCloserElementWithBinarySearch(arr, size, x, k);
    cout << "Closest Elements to " << x << " are: ";
    for (int num : ans)
        cout << num << " ";
    cout << endl;

    return 0;
}