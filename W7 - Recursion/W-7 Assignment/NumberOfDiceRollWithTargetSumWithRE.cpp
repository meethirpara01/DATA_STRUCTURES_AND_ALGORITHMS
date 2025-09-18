#include <iostream>
using namespace std;

int numRollsToTarget(int n, int& k, int t)
{
    // BASE CASE
    if (t < 0) return 0;
    if (n == 0 && t == 0) return 1;
    if (n != 0 && t == 0) return 0;
    if (n == 0 && t != 0) return 0;
    
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans = ans + numRollsToTarget(n - 1, k, t - i);
    }
    return ans;  
}

int main()
{
    int n;
    cout << "Enter Number Of Dice: ";
    cin >> n;
    
    int k;
    cout << "Enter Number Of Face In One Dice: ";
    cin >> k;
    
    int T;
    cout << "Enter Targeted Amount: ";
    cin >> T;

    int way = numRollsToTarget(n, k, T);
    cout << "NumberOf Way To Reach Target Is: " << way << endl;
    return 0;
}