#include <iostream>
using namespace std;

int numSquaresHelper(int n)
{
    // BASE CASE
    if (n == 0) return 1;
    if (n < 0) return 0;

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);
    while (i <= end)
    {
        int perfectSquare = i * i;
        int numberOfPerfectSquares = 1 + numSquaresHelper(n - perfectSquare);
        if (numberOfPerfectSquares < ans)
        {
            ans = numberOfPerfectSquares;
        }
        ++i;
    }
    return ans;
}

int numSquares(int n)
{
    return numSquaresHelper(n) - 1;
}
int main()
{
    int num;
    cout << "Enter An Number: ";
    cin >> num;

    int ans = numSquares(num);
    cout << "Minimum Number Of Perfect Squares Reqaired For This Numbers Is: " << ans << endl;
    return 0;
}