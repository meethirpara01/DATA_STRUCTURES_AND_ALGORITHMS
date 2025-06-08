#include<iostream>
using namespace std; 

string RemoveAllOccurenceSubString(string str, string part)
{
    while (str.find(part) != string::npos)
    {
        str.erase(str.find(part), part.length());
    }
    return str;
}

int main() 
{ 
    string str;
    cout << "Enter String: " ; 
    getline(cin, str);

    string part;
    cout << "Enter Sub Part Of String: " ;
    getline(cin, part);

    string ans = RemoveAllOccurenceSubString(str, part);
    cout << "Your Answer Is: " << ans << endl;
    return 0; 
}