// This Question Approches
// 1. Lineare Search (n2(squre)) check 1 to size Number Is Exist Or Not O(n^2)
// 2. First Sort The Array And And Check Evey Number Is <1 by Upcomeing Number (n logn)
// 3. SUM-Sum Of 1 to size and sum also element of array and Subtract Both Sum And Got The Answer O(n)
// 4. XOR Of An Element Of Array And Range Of Array O(n)

#include <iostream>
using namespace std;

void FindMissingElement(int arr[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];  
    }

    int n = size + 1; // since one number is missing
    int totalsum = (n * (n + 1)) / 2;
    int ans = totalsum - sum;
    cout << "Missing Number: " << ans << endl;
}

int main()
{
    int size;
    cout << "Enter Size Of Array (n-1): ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << (i + 1) << ": ";
        cin >> arr[i];
    }

    FindMissingElement(arr, size);

    return 0;
}
