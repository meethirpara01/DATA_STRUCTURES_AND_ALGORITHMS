#include<iostream>
using namespace std; 

bool isAlpha(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return true;
    return false;
}

string ReverseOnlyLetters(string str)
{
    int start = 0;
    int end = str.size() - 1;

    while (start <= end)
    {
        if (isAlpha(str[start]) && isAlpha(str[end]))
        {
            swap(str[start], str[end]);
            start++;
            end--;
        }
        else if (!isAlpha(str[start]))
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

    string ans = ReverseOnlyLetters(str);
    cout << "Your Reversed String Is: " << ans << endl;
    return 0; 
}