#include<iostream>
using namespace std; 

bool isPalindromin(string str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++, end--;
    }
    return true;
    
}
string LongestPalindromicString(string str)
{
    string ans = "";

    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i; j < str.size(); j++)
        {
            if (isPalindromin(str, i, j))
            {
                string t = str.substr(i, j - i + 1);
                ans = t.size() > ans.size() ? t : ans;
            }  
        } 
    }
    return ans;   
}

int main() 
{ 
    string str;
    cout << "Enter String : "; 
    getline(cin, str);

    string ans = LongestPalindromicString(str);
    cout << "YOUR LONGEST PALINDROMIC SUBSTRING IS: " << ans << endl;
    return 0; 
}