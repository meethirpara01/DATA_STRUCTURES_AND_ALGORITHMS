#include <iostream>
#include <vector>
using namespace std;


long merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    long c = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else // arr[j] > arr[i] INVERSION COUNT CASE
        {
            temp[k++] = arr[j++];
            c += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];
    
    while (start <= end)
    {
        arr[start] = temp[start];
        start++;
    }

    return c;
}

long mergeSort(vector<int>& arr, vector<int>& temp, int start, int end)
{
    if (start >= end) return 0;
    int mid = start + (end - start) / 2;
    long c = 0;
    c += mergeSort(arr, temp, start, mid);
    c += mergeSort(arr, temp, mid + 1, end);
    c += merge(arr, temp, start, mid, end);

    return c;  
}

long mergeSortCountInversion(vector<int>& arr)
{
    long c = 0; // INVERSION COUNT
    vector<int> temp(arr.size(), 0);
    c = mergeSort(arr, temp, 0, arr.size() - 1);

    return c;
}

int countInversionwithaitretive(vector<int>& arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }

    return count;
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

    long ans =  mergeSortCountInversion(arr);
    cout << "TOTAL INVERSION TO SORT ARRAY IS: " << ans << endl;
    
}