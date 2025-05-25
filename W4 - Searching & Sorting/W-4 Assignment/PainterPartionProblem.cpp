#include <iostream>
#include <numeric>

using namespace std;

bool isPosibleSolution(int arr[], int size, int painter, long long sol)
{
    long long timesum = 0;
    int c = 1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > sol)
            return false;
        if (timesum + arr[i] > sol)
        {
            c++;
            timesum = arr[i];
            if (c > painter)
                return false;
        }
        else
            timesum += arr[i];  
    }
    return true;
}

int BookAllocationFindPages(int arr[], int size, int painter)
{
    if (painter > size) return -1;
    
    long long start = 0;
    long long end = accumulate(arr, arr + size, 0);
    long long ans = -1;

    while (start <= end)
    {
        long long mid = (start + end) >> 1;
        if (isPosibleSolution(arr, size, painter, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;  
    }
    return ans;
    
}

int main()
{
    long long size;
    cout << "Enter Number Of Bord To Paint: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Number wood In Bord " << i + 1 << ": ";
        cin >> arr[i];
    }

    int painter;
    cout << "Enter Number Of Painter: ";
    cin >> painter;

    int ans = BookAllocationFindPages(arr, size, painter);
    cout << "Your Best Allocation Is With Maximum Number Of Bord Is: " << ans << endl;

    return 0;
}