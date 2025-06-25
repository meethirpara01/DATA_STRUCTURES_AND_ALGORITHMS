#include<iostream>
using namespace std; 

bool IsIsomorphicString(string s, string t)
{
    int hash[256] = {0};
    bool isCharMapped[256] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        if (hash[s[i]] == 0 && isCharMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];
            isCharMapped[t[i]] = true;
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (char(hash[s[i]]) != t[i])
        {
            return false;
        }
    }
    return true;
}

int main() 
{ 
    string s;
    cout << "Enter String S: " << endl; 
    getline(cin, s);

    string t;
    cout << "Enter String T: " << endl; 
    getline(cin, t);

    bool ans = IsIsomorphicString(s, t);
    (ans) ? cout << "Both String Are Isomorphic!" << endl : cout << "Both String Are Not Isomorphic!" << endl; 
    return 0; 
}