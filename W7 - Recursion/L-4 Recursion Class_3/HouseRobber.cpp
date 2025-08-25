#include<iostream>
using namespace std; 

int solve(vector<int> homes, int size, int index)
{
    if (index >= size)
    {
        return 0;
    }

    // CHORI HOGAI HAI -> iTH INDEX PER
    int option1 = homes[index] + solve(homes, size, index + 2);

    // CHORI NAHI KARI ABHI TAK -> iTH INDEX PER
    int option2 = 0 + solve(homes, size, index + 1);

    int finalAns = max(option1, option2);
    return finalAns;
}

int HouseRobberMaxMoney(vector<int> homes)
{
    int size = homes.size();
    int index = 0;
    int ans = solve(homes, size, index);
    return ans;
}

int main() 
{ 
    int size;
    cout << "Enter Number Of Coin: " << endl; 
    cin >> size;

    vector<int> homes(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Coin " << i + 1 << " : ";
        int input;
        cin >> input;
        homes.push_back(input);
    }

    int ans = HouseRobberMaxMoney(homes);
    cout << "To Make This Amount You Need To Use Number Of Coins Is: " << ans << endl;
    
    return 0; 
}