#include <iostream>
using namespace std;

int ountDerangement(int n)
{
    // BASE CASE
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;
    
    // RECURSIVE CALL
    int ans = (n - 1) * (ountDerangement(n - 1) + ountDerangement(n - 2));
    return ans;
}

int main()
{
    int N;
    cout << "Enter Length For Count Derangement For That Length: ";
    cin >> N;

    int ans = ountDerangement(N);
    cout << "Total Posible Derangement Is: " << ans << endl;
    return 0;
}