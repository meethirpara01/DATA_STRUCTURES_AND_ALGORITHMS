#include<iostream>
using namespace std; 

int convertToMins(string time)
{
    int hr = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3, 2));

    return 60 * hr + min;
}

int MinimumTimeDiffrence(vector<string> TimePoints)
{
    vector<int> mins;
    for (auto time: TimePoints)
        mins.push_back(convertToMins(time));

    sort(mins.begin(), mins.end());
    int ans = INT_MAX;
    for (int i = 0; i < mins.size() - 1; i++)
    {
        ans = min(ans, mins[i + 1] - mins[i]);
    }

    int lastDiff = mins[0] + 1440 - mins[mins.size() - 1];
    ans =  min(ans, lastDiff);

    return ans;
}
 
int main() 
{ 
    int times;
    cout << "Enter Number Of Times: ";
    cin >> times;
    cin.ignore(); // To clear leftover newline

    vector<string> TimePoints;
    for (int i = 0; i < times; i++) {
        string input;
        cout << "Enter Time In Form Of 'HH:MM' For " << i + 1 << ": ";
        getline(cin, input);
        TimePoints.push_back(input);
    }

    int ans = MinimumTimeDiffrence(TimePoints);
    cout << "Minimum Time Diffrence In Minuts is: " << ans << endl;

    return 0; 
}