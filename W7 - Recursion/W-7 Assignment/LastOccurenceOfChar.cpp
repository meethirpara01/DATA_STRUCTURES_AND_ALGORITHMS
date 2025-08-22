#include<iostream>
using namespace std; 

void LastOccrenceOfCharRTL(string str, char x,  int index, int& ans) // SEARCH RIGHT TO LEFT
{
    // BASE CASE
    if (index <= 0)
    {
        return;
    }
    
    // PROCCESSING
    if (str[index] == x)
    {
        ans = index;
        return;
    }

    // RECURSIVE CALL
    LastOccrenceOfCharRTL(str, x, index - 1, ans);
}

void LastOccrenceOfCharLTR(string str, char x,  int index, int& ans) // SEARCH LEFT TO RIGHT
{
    // BASE CASE
    if (index >= str.size())
    {
        return;
    }
    
    // PROCCESSING
    if (str[index] == x)
    {
        ans = index;
    }

    // RECURSIVE CALL
    LastOccrenceOfCharLTR(str, x, index + 1, ans);
}

int main() 
{ 
    string str;
    cout << "Enter An String: "; 
    getline(cin, str);

    char x;
    cout << "Enter Targeted Charechter: ";
    cin >> x;

    int ans = -1;
    LastOccrenceOfCharRTL(str, x, str.size() - 1, ans);
    cout << "Last Occrence Of Char In String Is : " << ans << endl;
    
    return 0; 
}