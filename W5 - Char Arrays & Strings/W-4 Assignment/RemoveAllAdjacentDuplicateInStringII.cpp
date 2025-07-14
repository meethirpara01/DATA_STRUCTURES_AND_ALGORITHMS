#include<iostream>
using namespace std; 
// TO SOLVE THIS QUESTION 
// 1. NEW ANS STRING O(N * K)
// 2. TWO POINTER O(N)
bool areLastK_1CharIsSame(string ans, char ch, int k_1)
{
    int it = ans.size() - 1;
    for (int i = 0; i < k_1; i++)
    {
        if (ch != ans[it])
            return false;
        it--;
    }

    return true;
}

string RemoveAllAdjacentDuplicates(string str, int k)
{
    string ans = "";
    for (int i = 0; i < str.size(); i++)
    {
        char & ch = str[i];

        if (ans.size() < k - 1)
        {
            ans.push_back(ch);
        }
        else
        {
            if (areLastK_1CharIsSame(ans, ch, k - 1))
            {
                for (int i = 0; i < k - 1; i++)
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans.push_back(ch);
            }  
        }
    }

    return ans;
}

string RemoveAllAdjacentDuplicatesWithTwoPointer(string str, int k)
{
    int i = 0;
    int j = 0;
    vector<int> count(str.size());

    while (j < str.size())
    {
        str[i] = str[j];
        count[i] = 1;
        if (i > 0 && str[i] == str[i - 1])
        {
            count[i] += count[i - 1];
        }
        if (count[i] == k)
        {
            i -= k;
        }
        i++, j++;
    }

    return str.substr(0, i);
}

int main() 
{ 
    string str;
    cout << "Enter String: "; 
    getline(cin, str);

    int k;
    cout << "Enter Seqaunce Of Duplicate Element: ";
    cin >> k;

    string ans = RemoveAllAdjacentDuplicatesWithTwoPointer(str, k);
    cout << "After Removel Of Duplicates In String: " << ans << endl;

    return 0; 
}