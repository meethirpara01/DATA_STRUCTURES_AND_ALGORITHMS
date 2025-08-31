#include<iostream>
using namespace std; 

int solve(vector<int> homes, int index, int size)
{
    if (index > size)
    {
        return 0;
    }

    // CHORI HOGAI HAI -> iTH INDEX PER
    int option1 = homes[index] + solve(homes, index + 2, size);

    // CHORI NAHI KARI ABHI TAK -> iTH INDEX PER
    int option2 = 0 + solve(homes, index + 1, size);

    int finalAns = max(option1, option2);
    return finalAns;
}

int HouseRobberMaxMoney(vector<int> homes)
{
    int size = homes.size();
    int index = 0;
    // SINGLE ELEMENT - CATCH
    if (size == 1)
        return homes[0];
    
    int option1 = solve(homes, index, size - 2);
    int option2 = solve(homes, index + 1, size - 1);
    int ans = max(option1, option2);
    return ans;
}

int main() 
{ 
    int size;
    cout << "Enter Number Of House: " << endl; 
    cin >> size;

    vector<int> homes(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Money In House " << i + 1 << " : ";
        int input;
        cin >> input;
        homes.push_back(input);
    }

    int ans = HouseRobberMaxMoney(homes);
    cout << "After Safe Robbery In House Maximum Amounte We Can Get Is: " << ans << endl;
    
    return 0; 
}