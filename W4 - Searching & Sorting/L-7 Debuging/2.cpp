// Debug the code. Find square root of x.
#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x == 0)
        return x;
    int first = 1, last = x;
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (mid == x / mid)
            return mid;
        else if (mid > x / mid)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return last;
}

int main()
{
    

    int x;
    cout << "Enter Target :" << endl;
    cin >> x;

    int ans = mySqrt(x);
    cout << "Posible Ans Is: " << ans << endl;

    return 0;
}



// RETURN VALUE IS MID I'L CHANGE TO -1;