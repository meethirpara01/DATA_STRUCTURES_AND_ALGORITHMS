#include<iostream>
using namespace std; 
// TO SOLVE THIS QUESTION 
// 1. COPY STRING AND CHECK BOTH ARE EQUALE O(N)
// 2. TWO POINTER APPROCH O(N)

bool checkpalindrome(string str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        else
        {
            start++;
            end--;
        }
        
    }
    return true;
}

bool checkPailndromeWithTwoPointer(string str)
{
    int start = 0;
    int end = str.length() - 1;

    while (start < end)
    {
        if (str[start] == str[end])
        {
            start++;
            end--;
        }
        else
        {
            bool ans1 = checkpalindrome(str, start + 1, end);
            bool ans2 = checkpalindrome(str, start, end - 1);

            return ans1 || ans2;
        } 
    }
    return true;
}

int main() 
{ 
    string str;
    cout << "Enter String" << endl; 
    getline(cin, str);

    bool ans = checkPailndromeWithTwoPointer(str);
    (ans) ? cout << "At Removel of Atmost One Charcter String Become Pailndrome.." << endl : cout << "At Removel of Atmost One Charcter String Can Not Become Pailndrome.." << endl;
    return 0; 
}