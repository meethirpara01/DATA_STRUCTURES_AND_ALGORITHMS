#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start,int mid, int end)
{

}

void mergeSort(vector<int>& arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (start - end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
    
}
void SortArrayUsingMergeSort(vector<int>& arr)
{
    mergeSort(arr, 0, arr.size() - 1);  
}
int main()
{
    int size;
    cout << "Enter Size Of Array: ";
    cin >> size;

    vector<int> arr(size);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Enter " << i + 1 << " Element :";
        cin >> arr[i];
    }

    SortArrayUsingMergeSort(arr);
    
}