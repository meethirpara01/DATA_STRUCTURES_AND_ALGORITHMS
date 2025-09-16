#include<iostream>
using namespace std; 

void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit) 
{
    // BASE CASE
    if (i == prices.size())
        return;

    // PROCCESSING
    if (prices[i] < minPrice)
        minPrice = prices[i];
    int todayProfit = prices[i] - minPrice;
    if (todayProfit > maxProfit)
        maxProfit = todayProfit;

    // RECURSIVE CALL
    maxProfitFinder(prices, i + 1, minPrice, maxProfit);
}

int maxProfit(vector<int>& prices)
{
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

int main() 
{ 
    int size;
    cout << "Enter An Size Of Array: "; 
    cin >> size;

    vector<int> prices(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Element " << i + 1 << " Of Array: ";
        cin >> prices[i];
    }

    int ans = maxProfit(prices);
    cout << "MaxProfit Possible In This Array iS: " << ans << endl;
    return 0; 
}