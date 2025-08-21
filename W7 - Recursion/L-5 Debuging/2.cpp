// 2. Debug the code.

#include <iostream>
using namespace std;

double myPow(double x, int n)
{
    int p = abs(n);
    double ans = 1.0;
    while (p >= 1)
    {
        if (p % 2 == 1)
        {
            ans *= x;
        }

        p /= 2;
        x *= x;
    }
    return n < 0 ? 1 / ans : ans;
}
int main()
{
    double x;
    cout << "Enter Floting Value: ";
    cin >> x;

    int n;
    cout << "Enter an Number : ";
    cin >> n;

    double ans = myPow(x, n);
    cout << ans << endl;
    return 0;
}

// IN THIS CODE NOT ADDED IF CONDITION