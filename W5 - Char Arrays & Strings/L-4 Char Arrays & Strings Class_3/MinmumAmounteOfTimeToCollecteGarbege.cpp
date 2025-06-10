#include <iostream>
#include <vector>
using namespace std;

int MinmumTimeToCollecteGarbage(vector<string> garbage, vector<int> travel)
{
    int pickP = 0;
    int pickM = 0;
    int pickG = 0;

    int travelP = 0;
    int travelM = 0;
    int travelG = 0;

    int lastP = 0;
    int lastM = 0;
    int lastG = 0;

    for (int i = 0; i < garbage.size(); i++)
    {
        string curr = garbage[i];

        for (auto ch : curr)
        {
            if (ch == 'P')
            {
                pickP++;
                lastP = i;
            }
            else if (ch == 'M')
            {
                pickM++;
                lastM = i;
            }
            else if (ch == 'G')
            {
                pickG++;
                lastG = i;
            }
        }  
    }

    for (int i = 0; i < lastP; i++)
    {
        travelP += travel[i];
    }

    for (int i = 0; i < lastM; i++)
    {
        travelM += travel[i];
    }

    for (int i = 0; i < lastG; i++)
    {
        travelG += travel[i];
    }

    return (pickP + travelP) + (pickM + travelM) + (pickG + travelG);
}
int main()
{
    int size;
    cout << "Enter Size of Garbage Collector: ";
    cin >> size;
    cin.ignore(); // Clear input buffer

    vector<string> garbage(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Garbage at Position " << i + 1 << ": ";
        getline(cin, garbage[i]);
    }

    vector<int> travel(size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        cout << "Enter Travel Time to Position " << i + 2 << ": ";
        cin >> travel[i];
    }

    cout << "\nGarbage:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Position " << i + 1 << ": " << garbage[i] << endl;
    }

    cout << "\nTravel Times:\n";
    for (int i = 0; i < size - 1; i++)
    {
        cout << "From " << i + 1 << " to " << i + 2 << ": " << travel[i] << " minutes" << endl;
    }

    int ans = MinmumTimeToCollecteGarbage(garbage, travel);
    cout << endl;
    cout << "Minmum Time To Collecte Garbage Is: " << ans << endl;

    return 0;
}
