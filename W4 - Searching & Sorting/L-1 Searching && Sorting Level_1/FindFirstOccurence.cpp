#include<iostream>
using namespace std; 

int FindFristOccurence(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            ans = mid;
            end = mid - 1;
        }
        else if(arr[mid] < target)
            start = mid + 1;
        else if(arr[mid] > target)
            end = mid - 1;
        
        mid = start + (end - start) / 2;
    }

    return ans;
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

    int ans = FindFristOccurence(arr, size, target);
    cout << "Target's First Occurence Is :  " << ans << endl;
    
    return 0; 
}