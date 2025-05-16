#include<iostream>
using namespace std; 

int FindTarget(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + (end - start)) / 2;

    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
            start = mid + 1; // ON THE A
        else // arr[mid] > arr [i + 1]
        {
            // ON THE PEAK OR ON THE B
            end = mid;
        }
        mid = (start + (end - start)) / 2;
    }

    return start;
}

int peakIndexInMountainArrayByLakshay(vector<int>& a) {
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
    cout << "Enter Size Of Array :" << endl; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << " Enter " << i + 1 << " Element : " ;
        cin >> arr[i];
    }
    
    int ans = FindTarget(arr, size);
    cout << "Peak Element : " << arr[ans] << endl;
    
    return 0; 
}