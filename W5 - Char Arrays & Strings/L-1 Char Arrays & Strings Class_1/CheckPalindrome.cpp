#include<iostream>
#include<string.h>
using namespace std; 
bool checkPalindrome(char ch[])
{
    int start = 0;
    int end = strlen(ch) - 1;

    while (start < end)
    {
        if (ch[start] == ch[end])
        {
            start++;
            end--;
        }
        else return false;
    }
    return true;
}

int main() 
{ 
    char ch[20];
    cout << "Enter String: " << endl; 
    cin.getline(ch, 20);

    int ans = checkPalindrome(ch);
    (ans) ? cout << "String Is Pailndrom " << endl : cout << "String Not Pailndrom " << endl;
    return 0; 
}