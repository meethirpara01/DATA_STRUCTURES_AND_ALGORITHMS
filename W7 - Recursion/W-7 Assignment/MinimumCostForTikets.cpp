#include <iostream>
using namespace std;

int mincostTickets_helper(vector<int>& days, vector<int> cost, int i)
{
    // BASE CASE
    if (i >= days.size())
        return 0;
    
    // PROCCESSING
    // SOLVE A ONE CASE
    // 1 DAY PASS TAKEN
    int cost1 = cost[0] + mincostTickets_helper(days, cost, i + 1);  // RECURSIVE CALL


    // 7 DAY PASS TAKEN
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndDay)
        j++;
    int cost7 = cost[1] + mincostTickets_helper(days, cost, j);  // RECURSIVE CALL


    // 30 DAY PASS TAKEN
    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndDay)
        j++;
    int cost30 = cost[2] + mincostTickets_helper(days, cost, j);  // RECURSIVE CALL


    return min(cost1, min(cost7, cost30));
}

int mincostTickets(vector<int>& days, vector<int> cost)
{
    return mincostTickets_helper(days, cost, 0);
}

int main()
{
    int size;
    cout << "Enter Number Of Days: ";
    cin >> size;

    vector<int> days(size);
    for (int i = 0; i < days.size(); i++)
    {
        cout << "Enter Day " << i + 1 << " : ";
        cin >> days[i];
    }

    vector<int> cost;
    cout << "Enter Cost For 1-DAY Pass: ";
    int input;
    cin >> input;
    cost.push_back(input);
    
    cout << "Enter Cost For 7-DAY Pass: ";
    cin >> input;
    cost.push_back(input);
    
    cout << "Enter Cost For 30-DAY Pass: ";
    cin >> input;
    cost.push_back(input);

    int ans = mincostTickets(days, cost);
    cout << "Minimum Number Of Doller You Need To Travel Is: " << ans << endl;

    return 0;
}