#include<iostream>
using namespace std; 

void removeOccureRE(string& str, string& part) 
{
    int found = str.find(part);
    if (found != string::npos)
    {
        // PART STRING HAS BEEN LOCATED
        // REMOVE IT
        string leftpart = str.substr(0, found);
        string rightpart = str.substr(found + part.size(), str.size());

        str = leftpart + rightpart;

        removeOccureRE(str, part);
    }
    else
    {
        // BASE CASE
        // ALL THE OCCURENCES OF PART HAS BEEN REMOVE FROM STR
        return;
    }  
}

string removeOccrence(string str, string part)
{
    removeOccureRE(str, part);
    return str;
}

int main() 
{ 
    string str;
    cout << "Enter An String: "; 
    getline(cin, str);

    string part;
    cout << "Enter An Part String: "; 
    getline(cin, part);

    string ans = removeOccrence(str, part);
    cout << "Final String Is: " << ans << endl;
    return 0; 
}