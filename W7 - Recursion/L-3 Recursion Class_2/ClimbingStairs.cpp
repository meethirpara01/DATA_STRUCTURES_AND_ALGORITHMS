#include<iostream>
using namespace std; 

int ClimbingStairsWays(int N)
{
    // BASE CASE
    if (N == 0)
    {
        return 1;
    }
    if (N == 1)
    {
        return 1;
    }

    // RECURSIVE CALL
    int way = ClimbingStairsWays(N - 1) + ClimbingStairsWays(N - 2);
    return way;
}

int main() 
{ 
    int Nth;
    cout << "Enter Nth Stair: "; 
    cin >> Nth;

    int ans = ClimbingStairsWays(Nth);
    cout << "To Rich That Nth Stair Total Number Of Way Is : " << ans << endl;
    return 0; 
}