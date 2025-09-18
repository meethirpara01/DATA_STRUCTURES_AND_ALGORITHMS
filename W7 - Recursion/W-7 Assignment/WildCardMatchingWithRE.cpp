#include <iostream>
using namespace std;

bool isMatchHelper(string& str, int si, string& p, int pi)
{
    // BASE CASE
    if (si == str.size() && pi == p.size())
        return true;

    if (si == str.size() && pi < p.size())
    {
        while (pi < p.size())
        {
            if (p[pi] != '*')
                return false;   
            pi++;
        }
        return true;
    }

    // PROCCESSING
    // SINGLE CHAR MATCHING
    if (str[si] == p[pi] || p[pi] == '?')
        return isMatchHelper(str, si + 1, p, pi + 1);  // RECURSIVE CALL
    
    if (p[pi] == '*')
    {
        // RECURSIVE CALL
        // TREAT '*' AS EMPTY OR NULL
        bool caseOne = isMatchHelper(str, si, p, pi + 1);

        //LET '*' CONSUME ONE CHAR
        bool caseTwo = isMatchHelper(str, si + 1, p, pi);
        return caseOne || caseTwo;
    }

    // CHAR DOSE'T MATCH
    return true;
}

bool wildcardMatching(string& str, string& p)
{
    int si = 0;
    int pi = 0;
    return isMatchHelper(str, si, p, pi);
}

int main()
{
    string str;
    cout << "Enter An String One: ";
    getline(cin, str);
    
    string p;
    cout << "Enter An String One: ";
    getline(cin, p);

    bool ans = wildcardMatching(str, p);
    ans ? cout << "Wild Card Matching" << endl : cout << "Wild Card Dose Not Matching" << endl;
    return 0;
}