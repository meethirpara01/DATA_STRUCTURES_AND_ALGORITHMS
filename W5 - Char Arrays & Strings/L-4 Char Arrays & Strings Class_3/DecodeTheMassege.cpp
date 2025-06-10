#include<iostream>
using namespace std; 

string DecodeTheMassege(string key, string massege)
{
    char start = 'a';
    char mapping[300] = {0}; 
    for(auto ch: key)
    {
        if (ch != ' ' && mapping[ch] == 0)
        {
            mapping[ch] = start;
            start++;
        }
    }

    string ans;
    for(auto ch:massege)
    {
        if (ch == ' ')
            ans.push_back(' ');
        else
        {
            char decodedChar = mapping[ch];
            ans.push_back(decodedChar);
        }  
    }
    return ans;

}
int main() 
{ 
    string key = "the quick brown fox jumps over the lazy dog";
    // cout << "Enter Key: " ; 
    // getline(cin, key);

    string massege;
    cout << "Enter Massege String: " ;
    getline(cin, massege);

    string ans = DecodeTheMassege(key, massege);
    cout << "Your Decoder Massege Is: " << ans << endl;
    return 0; 
}