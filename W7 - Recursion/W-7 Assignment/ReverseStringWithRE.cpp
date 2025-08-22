#include<iostream>
using namespace std; 

void ReverseAnString(string& str, char start,  int end) 
{
    // BASE CASE
    if (start >= end)
    {
        return;
    }
    
    // PROCCESSING
    swap(str[start], str[end]);

    // RECURSIVE CALL
    ReverseAnString(str, start + 1, end - 1);
}

int main() 
{ 
    string str;
    cout << "Enter An String: "; 
    getline(cin, str);

    int ans = -1;
    ReverseAnString(str, 0, str.size() - 1);
    cout << "Reversed String Is : ";

    for(auto ch : str)
    {
        cout << ch;
    }
    cout << endl;
    
    return 0; 
}