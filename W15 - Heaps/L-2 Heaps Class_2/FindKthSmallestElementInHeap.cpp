#include <iostream>
#include <queue>
using namespace std;

int getKthSmallestElement(int arr[], int size,int k)
{
    priority_queue<int> pq;
    // PROCCESS FIRST K ELEMENT
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        pq.push(element);
    }

    // ONLY INSERT REMAING ELEMENT IN THAT CASE IF THAT ELEMENT SMALLER THAN ROOT ELEMENT
    for (int i = k; i < size; i++)
    {
        int element = arr[i];
        if (element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;    
}


int getKthGretestElement(int arr[], int size,int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    // PROCCESS FIRST K ELEMENT
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        pq.push(element);
    }

    // ONLY INSERT REMAING ELEMENT IN THAT CASE IF THAT ELEMENT SMALLER THAN ROOT ELEMENT
    for (int i = k; i < size; i++)
    {
        int element = arr[i];
        if (element > pq.top()) // CHANGE ONLY THIS SIGN TO FIND GRETEST ELEMENT
        {
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();
    return ans;    
}

int main()
{
    int size;
    cout << "Eneter Size Of Array: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "ENTER " << i + 1 << " ELEMENT OF ARRAY: ";
        cin >> arr[i];
    }

    int k;
    cout << "ENTER VALUE OF K: ";
    cin >> k;
    
    int ans1 = getKthSmallestElement(arr, size, k);
    cout << "Kth SMALLEST ELEMENT IN THIS ARRAY IS: " << ans1 << endl;
    
    int ans2 = getKthGretestElement(arr, size, k);
    cout << "Kth GREATEST ELEMENT IN THIS ARRAY IS: " << ans2 << endl;
    cout << endl;
    // 3 5 4 6 9 8 7
    return 0;
}