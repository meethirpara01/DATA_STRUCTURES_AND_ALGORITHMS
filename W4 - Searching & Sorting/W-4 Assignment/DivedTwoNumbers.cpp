#include<iostream>
using namespace std; 

int DivedTwoNumber(int divisor , int dividend)
{
    int start = 0;
    int end = dividend;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid * divisor <= dividend)
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return ans;  
}

double DivedTwoNumberWithPoint(int divisor , int dividend)
{
    double ans = DivedTwoNumber(abs(divisor) ,abs(dividend));
    double step = 0.1;
    double precision = 10;

    for (int i = 0; i < precision; i++)
    {
        double j = ans;
        while (j * divisor <= dividend)
        {
            ans = j;
            j += step;
        }
        step /= 10;
    }
    return ans;
}


int main() 
{ 
    int divisor;
    cout << "Enter Divisor" << endl; 
    cin >> divisor;

    int dividend;
    cout << "Enter Dividend" << endl; 
    cin >> dividend;

    double ans = DivedTwoNumberWithPoint(abs(divisor) ,abs(dividend));
    if (divisor < 0 && dividend >0 || divisor > 0 && dividend < 0)
        ans = -ans;
    printf("%0.10f", ans);
    cout << endl;
    cout << "Your Answer Is: " << ans << endl;

    return 0; 
}