#include<iostream>
using namespace std; 

int FindSqrt(int num)
{
    int start = 0;
    int end = num;
    long long int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if ((mid * mid) == num)
            return mid;
        else if (mid * mid < num)
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main() 
{
    int num;
    cout << "Enter Number:" << endl; 
    cin >> num;
   
    int ans = FindSqrt(num);
    cout << "SQURE RUTE IS :" << ans << endl;
    
    return 0; 
}