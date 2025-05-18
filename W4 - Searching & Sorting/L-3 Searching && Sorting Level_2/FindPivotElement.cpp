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
        {
            return start;
        }
        else
        {
            if (arr[mid - 1] >= 0 && arr[mid] < arr[mid - 1]) // HERE IS CATCH CONDITION IS MENDETARY
                return mid - 1;
            else if (arr[mid + 1] < size - 1 && arr[mid] > arr[mid + 1]) // // HERE IS CATCH CONDITION IS MENDETARY
                return mid;
            else if (arr[start] > arr[mid])
                end = mid - 1;
            else
                start = mid + 1; // IF WE WRITE THIS CONDTION IN IF THAN WE NEED TO ADD = CONDTION TO UNDERSTAND WATCH NOTES EXAMPLE AND IF OUR MID IS ON ARR[S] THAT'S WHY WE NEED = CONDITION (arr[start] <= arr[mid])
            
            mid = start + (end - start) / 2;
        } 
    }
    return -1;
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

    int ans = FindPivotElement(arr, size);
    cout << "Pivot Index Is :" << ans << endl;
    
    return 0; 
}