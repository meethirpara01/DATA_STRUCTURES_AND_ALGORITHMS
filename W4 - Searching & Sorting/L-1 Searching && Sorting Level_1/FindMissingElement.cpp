#include <iostream>
using namespace std;

int FindlastOccurence(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        int diff = arr[mid] - mid;

        if (ans + 1 == 0)
            ans = size + 1;
        else
        {
            if (diff == 1)
            {
                start = mid + 1;
            }
            else
            {
                ans = mid + 1;
                end = mid - 1;
            }
        }
        mid = start + (end - start) / 2;
    }

    // if (ans + 1 == 0)
    //     return size + 1;

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
        cout << " Enter " << i + 1 << " Element : ";
        cin >> arr[i];
    }

    int ans = FindlastOccurence(arr, size);
    cout << "Missing Element In Array Is :  " << ans << endl;

    return 0;
}