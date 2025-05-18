#include<iostream>
using namespace std; 

int DiviedTwoNumbers(int dividend, int divisor)
{
    int start = 0;
    int end = dividend;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (mid * divisor == dividend)
            return mid;
        else if (mid * divisor < dividend)
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
    int dividend;
    cout << "Enter a Diviend" << endl; 
    cin >> dividend;

    int divisor;
    cout << "Enter a Divisor" << endl; 
    cin >> divisor;

    int ans = DiviedTwoNumbers(abs(dividend), abs(divisor));
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        ans = -ans;
    
    cout << "YOUR ANSWER IS: " << ans << endl;
    return 0; 
}