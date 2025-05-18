#include<iostream>
using namespace std; 

int FindTarget(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (start == end)
            return start;
        if ((mid & 1) == 0) // CATCH
        {
            if (mid + 1 < size && arr[mid] == arr[mid + 1])
                start = mid + 2; // CATCH
            else
                end = mid; // CATCH
        }
        else
        {
            if (mid - 1 >= 0 && arr[mid] == arr[mid - 1])
                start = mid + 1;
            else
                end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return -1;
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
    cout << "UNIIQ ELEMENT IS: " << arr[ans] << endl;
    
    return 0; 
}