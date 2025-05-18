#include<iostream>
using namespace std; 

int FindPivotElement(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (start == end)
            return start;
        else
        {
            if (arr[mid - 1] >= 0 && arr[mid] < arr[mid - 1]) // HERE IS CATCH CONDITION IS MENDETARY TO MANTAINE RANG
                return mid - 1;
            else if (arr[mid + 1] < size - 1 && arr[mid] > arr[mid + 1]) // // HERE IS CATCH CONDITION IS MENDETARY MANTAINE RANG
                return mid;
            else if (arr[start] > arr[mid])
                end = mid - 1;
            else
                start = mid + 1; // IF WE WRITE THIS CONDTION IN IF THAN WE NEED TO ADD = CONDTION TO UNDERSTAND WATCH NOTES EXAMPLE AND IF OUR MID IS ON ARR[S] THAT'S WHY WE NEED = CONDITION (arr[start] <= arr[mid])
        } 
        mid = start + (end - start) / 2; 
    }
    return -1;
}

int BinarySearch(int arr[], int start, int end, int target)
{
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == target)
            return mid; 
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return -1;
}

int Search(int arr[], int size, int target)
{
    
    int pivotIndex = FindPivotElement(arr, size);
    int ans = -1;

    if (target >= arr[0] && target <=  arr[pivotIndex])
        ans = BinarySearch(arr, 0, pivotIndex, target);
    else
        ans = BinarySearch(arr, pivotIndex + 1, size - 1, target);

    return ans; 
}

int main() 
{
    int size;
    cout << "Enter Size Of Array:" << endl; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array Element " << i + 1 << ": " ;
        cin >> arr[i];
    }

    int target;
    cout << "Enter target:" << endl; 
    cin >> target;

    int ans = Search(arr, size, target);

    if (ans != -1)
        cout << "Target Is Found :" << arr[ans] << endl;
    else
        cout<< "Target Not Found" << endl;

    return 0; 
}