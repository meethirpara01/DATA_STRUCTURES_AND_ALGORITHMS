#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 1 GAS = 1 DISTANCE
int gasStation(vector<int> &gas, vector<int> &distance)
{
    int deficit = 0;
    int balance = 0;

    int start = 0;
    
    for (int i = 0; i < gas.size(); i++)
    {
        balance = balance + gas[i] - distance[i];

        if (balance < 0)
        {
            deficit += abs(balance);
            start = i + 1;
            balance = 0;
        }
    }

    if (balance - deficit >= 0)
    {
        return start;
    }
    else
        return -1;
}

int main()
{
    int size;
    cout << "Enter Number Of Station: ";
    cin >> size;

    vector<int> gas(size);
    for (int i = 0; i < size; i++)
    {
        cout << "ENTER HOW MUCH GAS PRESENT ON STATION " << i + 1 << ": ";
        cin >> gas[i];
    }
    
    vector<int> distance(size);
    for (int i = 0; i < size; i++)
    {
        cout << "ENTER HOW MANY DISTANCE FROM CURRENT STATION TO NEXT STATION " << i + 1 << ": ";
        cin >> distance[i];
    }

    int ans = gasStation(gas, distance);
    if (ans != -1)
        cout << "YOU CAN COMPLETE YOUR CYCLE STARTING FROM GAS STATION NO: " << ans + 1 << endl;
    else
        cout << "YOU CANNOT COMPLETE YOUR CYCLE FROM ANY STATION." << endl;
    
    return 0;
}