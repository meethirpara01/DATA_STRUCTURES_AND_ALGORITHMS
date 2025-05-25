#include <iostream>
#include <numeric>

using namespace std;

bool isPosibleSolution(int arr[], int size, int student, int sol)
{
    int pagesum = 0;
    int c = 1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > sol)
            return false;
        if (pagesum + arr[i] > sol)
        {
            c++;
            pagesum = arr[i];
            if (c > student)
                return false;
        }
        else
            pagesum += arr[i];  
    }
    return true;
}

int BookAllocationFindPages(int arr[], int size, int student)
{
    if (student > size) return -1;
    
    int start = 0;
    int end = accumulate(arr, arr + size, 0);
    int ans = -1;

    while (start <= end)
    {
        int mid = (start + end) >> 1;
        if (isPosibleSolution(arr, size, student, mid))
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
    int size;
    cout << "Enter Number Of Book: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Number Page Of Book " << i + 1 << ": ";
        cin >> arr[i];
    }

    int student;
    cout << "Enter Number Of Student: ";
    cin >> student;

    int ans = BookAllocationFindPages(arr, size, student);
    cout << "Your Best Allocation Is With Maximum Number Of Page Is: " << ans << endl;

    return 0;
}