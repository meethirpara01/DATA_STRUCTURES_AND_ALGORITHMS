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

string RemoveAllOccurenceSubStringUsingConcatination(string str, string part)
{   
    while (1)
    {
        int found = str.find(part);
        if (found == string::npos) break;

        string LP = str.substr(0, found);
        string RP = str.substr(found + part.size(), str.size());

        str = LP + RP;
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

    string ans = RemoveAllOccurenceSubStringUsingConcatination(str, part);
    cout << "Your Answer Is: " << ans << endl;
    return 0; 
}