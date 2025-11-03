#include <iostream>
#include <deque>
using namespace std;

void printFirstNegetiveInWindow(int arr[], int size, int k)
{
    deque<int> dq;

    // PROCCESS FIRST K ELEMENT - FIRST WINDOW
    for (int index = 0; index < k; index++)
    {
        int element = arr[index];
        if (element < 0)
        {
            dq.push_back(index);
        }
    }

    // PROCCESS REMAINING WINDOWS -> REMOVAL AND ADDICTION
    for (int i = k; i < size; i++)
    {
        // BEFORE YOU MOVE AHEAD TAKE OUT ANSWER OF THE REAR WINDOW
        if (dq.empty())
            cout << "0" << endl;
        else
            cout << arr[dq.front()] << " ";      
            
            
        // REMOVAL - REMOVE INDEX WHICH ARE OUT OF RANGE
        if (i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // ADDICTION
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // PRINT ANSWER OF LAST WINDOW
    if (dq.empty())
        cout << "0" << endl;
    else
        cout << arr[dq.front()] << " ";
}

int main()
{
    int size;
    cout << "Enter Size Of Array: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " Value Of Array: ";
        cin >> arr[i];
    }

    int k;
    cout << "Enter Kth Vlaue: ";
    cin >> k;

    printFirstNegetiveInWindow(arr, size, k);
    return 0;
}