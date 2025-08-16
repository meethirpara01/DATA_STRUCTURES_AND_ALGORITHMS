#include<iostream>
using namespace std; 

bool FindTargetInString(string str, char Target, int index)
{

    if (str[index] == '\0')
    {
        return false;
    }

    if (str[index] == Target)
    {
        return true;
    }

    bool agekaAns = FindTargetInString(str, Target, index + 1);
    return agekaAns;
}

int main() 
{ 
    string str;
    cout << "Enter An String: " << endl; 
    getline(cin, str);

    char Target;
    cout << "Enter An Target Charachter: " << endl; 
    cin >> Target;

    bool ans = FindTargetInString(str, Target, 0);
    ans ? cout << "Target Found" << endl : cout << "Target Not Found" << endl;
    cout << endl;

    return 0; 
}