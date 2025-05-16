#include<iostream>
using namespace std; 

int FindFristOccurence(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int FristOccurence = -1;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            FristOccurence = mid;
            end = mid - 1;
        }
        else if(arr[mid] < target)
            start = mid + 1;
        else if(arr[mid] > target)
            end = mid - 1;
        
        mid = start + (end - start) / 2;
    }

    return FristOccurence;
}

int FindlastOccurence(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int lastOccurence = -1;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            lastOccurence = mid;
            start = mid + 1;
        }
        else if(arr[mid] < target)
            start = mid + 1;
        else if(arr[mid] > target)
        // else 
            end = mid - 1;
        
        mid = start + (end - start) / 2;
    }

    return lastOccurence;
}

int main() 
{ 
    int size;
    cout << "Enter Size Of Array :" << endl; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << " Enter " << i + 1 << " Element : " ;
        cin >> arr[i];
    }

    int target;
    cout << "Enter Target :" << endl; 
    cin >> target;

    int FristOccurence = FindFristOccurence(arr, size, target);
    int lastOccurence = FindlastOccurence(arr, size, target);
    int TotalOccurence =  lastOccurence - FristOccurence + 1;
    cout << "Target's Total Occurence Is :  " << TotalOccurence << endl;
    
    return 0; 
}