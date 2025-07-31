#include<iostream>
using namespace std; 

bool isVowel(char ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
string ReverseOnlyVowels(string str)
{
    int start = 0;
    int end = str.size() - 1;

    while (start < end)
    {
        if (isVowel(str[start]) & isVowel(str[end]))
        {
            swap(str[start], str[end]);
            start++;
            end--;
        }
        else if (!isVowel(str[start]))
            start++;
        else
            end--;
    }
    return str;
}
int main() 
{ 
    string str;
    cout << "Enter String: " << endl; 
    getline(cin, str);

    string ans = ReverseOnlyVowels(str);
    cout << "Your Reversed String: " << ans << endl;
    return 0; 
}