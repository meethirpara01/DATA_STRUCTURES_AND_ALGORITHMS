#include <iostream>
#include <vector>
using namespace std;

string LongestCommonPrefix(vector<string> Words)
{
    string ans;
    int i = 0;
    while (true)
    {
        char curr_ch = 0;
        for (auto word : Words)
        {
            if (i >= word.size())  // avoid out-of-range access
            {
                curr_ch = 0;
                break;
            }

            if (curr_ch == 0)
            {
                curr_ch = word[i];
            }
            else if (word[i] != curr_ch)
            {
                curr_ch = 0;
                break;
            }
        }
        if (curr_ch == 0)
        {
            break;
        }
        ans.push_back(curr_ch);
        i++;
    }
    return ans;
}

int main()
{
    int size;
    cout << "Enter Number Of Words: " << endl;
    cin >> size;
    
    cin.ignore();

    vector<string> Words(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << "st Word: ";
        getline(cin, Words[i]);
    }

    string ans = LongestCommonPrefix(Words);
    cout << "Your Longest Common Prefix Is: " << ans << endl;

    return 0;
}