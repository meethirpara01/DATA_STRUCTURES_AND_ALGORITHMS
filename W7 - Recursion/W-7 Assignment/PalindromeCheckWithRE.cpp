#include<iostream>
using namespace std; 

bool PalindromeCheck(string& str, char start,  int end) 
{
    // BASE CASE
    if (start >= end)
    {
        return true;
    }

    // PROCCESSING
    if (str[start] != str[end])
    {
        return false;
    }
    
    // RECURSIVE CALL
    return PalindromeCheck(str, start + 1, end - 1);
}

int main() 
{ 
    string str;
    cout << "Enter An String: "; 
    getline(cin, str);

    bool ans = PalindromeCheck(str, 0, str.size() - 1);
    ans ? cout << " String Is Palindrome " << endl : cout << " String Is Not An Palindrome " << endl;
    
    return 0; 
}