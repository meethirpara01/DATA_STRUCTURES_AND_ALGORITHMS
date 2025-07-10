#include<iostream>
#include <map>
#include<vector>
using namespace std; 
// TO SOLVE THIS QUESTION 
//  1. MAP
//  2. HASH MAP
 
vector<vector<string>> GroupOfAnagramWithMap(vector<string> strs)
{
    map<string, vector<string> >mp;

    for (auto str: strs)
    {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }

    vector<vector<string>> ans;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}

array<int, 256> hash(string s)
{
    array<int, 256>hash = {0};

    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }

    return hash;
}

vector<vector<string>> GroupOfAnagramWithHash(vector<string> strs)
{

    map<array<int, 256>, vector<string> >mp;

    for (auto str: strs)
    {
        // mp[hash(str)].push_back(str);
    }

    vector<vector<string>> ans;
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
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

    vector<vector<string>> ans = GroupOfAnagramWithHash(Words);
    // cout << "Your Longest Common Prefix Is: " << ans << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]";
    }
    

    return 0;
}