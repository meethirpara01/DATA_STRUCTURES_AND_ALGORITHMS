#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

bool isPosibleSolution(vector<int> arr, int size, int prata, int sol)
{
    int cuurp = 0;
    for (int i = 0; i < size; i++)
    {
        int r = arr[i];
        int j = 1;
        int timetacken = 0;
        
        while (true)
        {
            if (timetacken + j * r <= sol)
            {
                ++cuurp;
                timetacken += j * r;
                ++j;
            }
            else break;
        }
        if (cuurp >= prata)
        {
            return true;
        }   
    }
    return false;

}

int FindMinTimeToMakePrata(vector<int> arr, int size, int prata)
{
    
    int start = 0;
    int highestRank = *max_element(arr.begin(), arr.end());
    int end = highestRank * prata * (prata + 1) / 2;
    int ans = -1;

    while (start <= end)
    {
        int mid = (start + end) >> 1;
        if (isPosibleSolution(arr, size, prata, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;  
    }
    return ans;
}

int main()
{
    int size;
    cout << "Enter Number Of Cook: ";
    cin >> size;

    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Rank Of Cook " << i + 1 << ": ";
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int prata;
    cout << "How Many Parata You Want To Make: ";
    cin >> prata;

    int ans = FindMinTimeToMakePrata(arr, size, prata);
    cout << "Your Best Allocation Is With Minimum To Make Parata Is: " << ans << endl;

    return 0;
}