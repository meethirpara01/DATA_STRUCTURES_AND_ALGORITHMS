#include <iostream>
using namespace std;

int PaintingFenceTotalWay(int n, int k)
{
    // BASE CASE
    if (n == 1)
        return k;

    if (n == 2)
        return k +  (k * (k - 1));
    
    // RECURSIVE CALL
    int ans = (k - 1) * (PaintingFenceTotalWay(n - 1, k) + PaintingFenceTotalWay(n - 2, k));
    return ans;
}

int main()
{
    int N;
    cout << "Enter Number Of Post: ";
    cin >> N;
    
    int K;
    cout << "Enter Number Of Colume: ";
    cin >> K;

    int ans = PaintingFenceTotalWay(N, K);
    cout << "Total Posible Way Is: " << ans << endl;
    return 0;
}