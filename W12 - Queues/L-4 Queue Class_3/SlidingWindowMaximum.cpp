#include <iostream>
#include <deque>
using namespace std;

vector<int> printFirstNegetiveInWindow(int arr[], int size, int k)
{
    vector<int> ans;
    deque<int> dq;

    // PROCCESS FIRST K ELEMENT - FIRST WINDOW
    for (int index = 0; index < k; index++)
    {
        int element = arr[index];
        while (!dq.empty() && element > arr[dq.back()])
        {
            dq.pop_back();
        }

        // AND INSERT THAT ELEMENT IN TO DQ
        dq.push_back(index);
    }

    // PROCCESS REMAINING WINDOWS -> REMOVAL AND ADDICTION
    for (int i = k; i < size; i++)
    {
        // BEFORE YOU MOVE AHEAD TAKE OUT ANSWER OF THE REAR WINDOW
        // NO NEED TO CHECK DQ IS EMPTY OR NOT BECAUSE WE HAVE TO SOTE ATLEST ONE MAX ELEMENT
        ans.push_back(arr[dq.front()]);
              
        // REMOVAL - REMOVE INDEX WHICH ARE OUT OF RANGE
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        
        // POP SMALL ELEMENT
        int element = arr[i];
        while (!dq.empty() && element > arr[dq.back()])
        {
            dq.pop_back();
        }

        // AND INSERT THAT ELEMENT IN TO DQ
        dq.push_back(i);
    }

    // PRINT ANSWER OF LAST WINDOW
    // NO NEED TO CHECK DQ IS EMPTY OR NOT BECAUSE WE HAVE TO SOTE ATLEST ONE MAX ELEMENT
    ans.push_back(arr[dq.front()]);

    return ans;
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

    vector<int> ans = printFirstNegetiveInWindow(arr, size, k);
    for(auto elem: ans)
    {
        cout << elem << "->";
    }
    return 0;
}