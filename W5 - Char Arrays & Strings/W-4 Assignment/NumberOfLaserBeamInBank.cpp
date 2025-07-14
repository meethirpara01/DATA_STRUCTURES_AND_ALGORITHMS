#include<iostream>
#include<vector>
using namespace std;

int countDevices(string binary)
{
    int c = 0;
    for (auto b : binary)
        c += b - '0';
    return c;
}

int NumberOfLaserBeams(vector<string> Bank)
{
    vector<int> Devices;
    for (auto row : Bank) {
        int d = countDevices(row);
        if (d > 0)
            Devices.push_back(d);  // Only non-zero device rows matter
    }

    int beam = 0;
    for (int i = 0; i < Devices.size() - 1; i++) {
        beam += Devices[i] * Devices[i + 1];
    }

    return beam;
}

int main()
{
    int floor;
    cout << "Enter Number Of Floor Plan: ";
    cin >> floor;
    cin.ignore(); // To clear leftover newline

    vector<string> Bank;
    for (int i = 0; i < floor; i++) {
        string input;
        cout << "Enter Security Layers In Form Of 0 And 1 For Floor " << i + 1 << ": ";
        getline(cin, input);
        Bank.push_back(input);
    }

    int ans = NumberOfLaserBeams(Bank);
    cout << "Number Of Laser Beams In The Bank: " << ans << endl;

    return 0;
}
