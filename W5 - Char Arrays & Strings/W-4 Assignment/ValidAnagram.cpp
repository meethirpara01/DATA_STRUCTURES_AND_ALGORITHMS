#include<iostream>
using namespace std; 
// TO SOLVE THIS QUESTION 
// 1. SORTH BOTH STRING AND CHECK BOTH ARE EQUALE OR NOT O(n log n)
// 2. COUNTING WITH MAPING

bool IsAnagram(string s, string t)
{
    int mapping[300]  = {0};
    for(int i = 0; i < s.size(); i++)
        mapping[s[i]]++;

    for(int i = 0; i < t.size(); i++)
        mapping[t[i]]--;

    for(int i = 0; i < 300; i++)
    {
        if (mapping[i] != 0)
            return false;
    }
    return true;
}

int main() 
{ 
    string s;
    cout << "Enter String Called S: " << endl; 
    getline(cin, s);

    string t;
    cout << "Enter String Called T: " << endl; 
    getline(cin, t);

    bool ans = IsAnagram(s, t);
    (ans) ? cout << "Your Both String Are Anagram!" << endl : cout << "Your Both String Are Not An Anagram!" << endl;

    return 0; 
}