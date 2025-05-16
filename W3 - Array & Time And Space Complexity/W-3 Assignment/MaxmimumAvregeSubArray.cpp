#include<iostream>
using namespace std; 
// Approch For This Question 
// 1. Brute Force O(n^2)
// 2. SlideingWindows O(n)
void FindMamimumAvrege(int arr[], int size, int k)
{
    int maxSum = INT_MIN;
    int i = 0;
    int j = k - 1;

    while (j < size)
    {
        int sum = 0;
        for (int s = 0; s <= j; s++)
        {
            sum += arr[s];
        }
        maxSum = max(maxSum, sum);
        i++;
        j++;
    }
    double maxAvg = maxSum / (double)k;
    cout << "Our Maxmimum Avrege Is : " << maxAvg << endl;
}

void FindMamimumAvregeWithSlidingWindows(int arr[], int size, int k)
{
    int maxSum = INT_MIN;
    int i = 0;
    int j = k - 1;
    int sum = 0;
 
    for (int s = 0; s <= j; s++)
    {
        sum += arr[s];
    }
    maxSum = max(maxSum, sum);
    j++;
    while (j < size)
    {
        sum -= arr[i++];
        sum += arr[j++];
        maxSum = max(maxSum, sum);
    }  
    double maxAvg = maxSum / (double)k;
    cout << "Our Maxmimum Avrege Is : " << maxAvg << endl;
}


int main() 
{ 
    int size;
    cout << "Enter Size Of Array :" << endl; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element Of Array " << i << " : ";
        cin >> arr[i];
    }

    int k;
    cout << "Enter Size Of Sub Array :" << endl; 
    cin >> k;

    FindMamimumAvregeWithSlidingWindows(arr, size, k);
    
    return 0; 
}