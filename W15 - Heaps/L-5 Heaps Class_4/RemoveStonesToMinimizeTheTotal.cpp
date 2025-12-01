#include <iostream>
using namespace std;

int minStoneSum(vector<int>& piles, int k)
{
    priority_queue<int> maxHeap;

    for (int i = 0; i < piles.size(); i++)
    {
        int element = piles[i];
        maxHeap.push(element);
    }

    while (k--)
    {
        int topElement = maxHeap.top();
        maxHeap.pop();
        topElement =  topElement - floor(topElement / 2);
        maxHeap.push(topElement);
    }

    int sum = 0;
    while (!maxHeap.empty())
    {
        int top = maxHeap.top();
        sum += top;
        maxHeap.pop();
    }

    return sum;
}

int main()
{
    int size;
    cout << "ENTER SIZE OF ARRAY: ";
    cin >> size;

    vector<int> piles(size);
    for (int i = 0; i < size; i++)
    {
        cout << "ENTER ELEMENT " << "[" << i + 1  << "] OF ARRAY: ";
        cin >> piles[i]; 
    }

    int k;
    cout << "ENTER NUMBER OF ARRAY: ";
    cin >> k;

    int ans = minStoneSum(piles, k);
    cout << "AFTER REMOVEING STONES WITH K OPRATIONS MINIMIZE THE TOTAL IS: " << ans << endl;
    return 0;
}