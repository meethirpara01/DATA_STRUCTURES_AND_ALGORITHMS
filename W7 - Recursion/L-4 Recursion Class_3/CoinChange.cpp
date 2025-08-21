#include<iostream>
using namespace std; 

int solve(vector<int> coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }

    int mini = INT_MAX;
    int ans = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];

        // CURRENT COIN KO SIRF THBHI USE KARENGE 
        // JAB USKI VALUE <= AMOUNT HOGI

        if (coin <= amount)
        {
            int recAns = solve(coins, amount - coin);
            if (recAns != INT_MAX)
            {
                ans = 1 + recAns;
            }

            mini = min(mini, ans);
        }  
    }
    return mini;
}

int solve1(vector<int> coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }

    if (amount < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];

        // CURRENT COIN KO SIRF THBHI USE KARENGE 
        // JAB USKI VALUE <= AMOUNT HOGI

        if (coin <= amount)
        {
            int recAns = solve1(coins, amount - coin);
            if (recAns != INT_MAX)
            {
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }  
        }
    }
    return mini;
}

int coinsChange(vector<int> coins, int amount)
{
    int ans = solve(coins, amount);
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}

int main() 
{ 
    int size;
    cout << "Enter Number Of Coin: " << endl; 
    cin >> size;

    vector<int> coins(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Coin " << i + 1 << " : ";
        int input;
        cin >> input;
        coins.push_back(input);
    }

    int amount;
    cout << "Enter Target Amount: ";
    cin >> amount;

    int ans = coinsChange(coins, amount);
    cout << "To Make This Amount You Need To Use Number Of Coins Is: " << ans << endl;
    
    return 0; 
}