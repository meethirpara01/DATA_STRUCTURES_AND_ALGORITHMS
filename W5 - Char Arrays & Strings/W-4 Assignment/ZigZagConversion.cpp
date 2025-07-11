#include<iostream>
using namespace std; 

string ZigZagConversion(string str, int NumOfRow)
{
    if (NumOfRow == 1) return str;
    
    int i = 0;
    int row = 0;
    bool direction = 1;

    vector<string> ZigZag(NumOfRow);

    while (true)
    {
        if (direction)
        {
            while (row < NumOfRow && i < str.size())
            {
                ZigZag[row++].push_back(str[i++]);
            }
            row = NumOfRow - 2;            
        }
        else
        {
            while (row >= 0 && i < str.size())
            {
                ZigZag[row--].push_back(str[i++]);
            }
            row = 1;
        }

        if (i >= str.size()) break;
        direction = !direction;
    }

    string ans = "";
    for (int i = 0; i < ZigZag.size(); i++)
    {
        ans += ZigZag[i];
    }
    return ans;
}

int main() 
{ 
    string str;
    cout << "Enter String: "; 
    getline(cin, str);

    int NumOfRow;
    cout << "Enter Number Of Row: "; 
    cin >> NumOfRow;

    string ans = ZigZagConversion(str, NumOfRow);
    cout << "YOUR ZIGZAG STRING IS: " << ans << endl;
    return 0; 
}