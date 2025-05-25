#include <iostream>
#include <numeric>

using namespace std;

bool isPosibleSolution(int arr[], int size, int cow, int sol)
{
    int c = 1;
    int pos = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] - pos >= sol)
        {
            c++;
            pos = arr[i];
        }
        if (c == cow) return true;
    }
    return false;
}


int FindMaxPosition(int arr[], int size, int cow)
{
    sort(arr, arr + size);
    
    int start = 0;
    int end = arr[size - 1] - arr[start];
    int ans = -1;

    while (start <= end)
    {
        int mid = (start + end) >> 1;
        if (isPosibleSolution(arr, size, cow, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;  
    }
    return ans;
    
}

int main()
{
    int size;
    cout << "Enter Number Of Stall: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Position Of Book " << i + 1 << ": ";
        cin >> arr[i];
    }

    int cow;
    cout << "Enter Number Of Cow: ";
    cin >> cow;

    int ans = FindMaxPosition(arr, size, cow);
    cout << "Your Best Allocation Is With Minmum Diffrence Between Cow Is: " << ans << endl;

    return 0;
}