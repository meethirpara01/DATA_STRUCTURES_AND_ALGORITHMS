#include <iostream>
#include<stack>
using namespace std;

bool isValidPrentheses(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }

        else if (ch == ')')
        {
            int opratorCount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    opratorCount++;
                }
                st.pop();
            }

            // ONLY IN ONE CASE YOU CAN REACH HERE THAT IS STACK TOP IS EQUAL TO OPENING BRACKET
            st.pop();

            if (opratorCount == 0)
            {
                return true;
            }   
        }
    }

    // NOW YOU STILL REACH HERE THAT MEAN OPRATORCOUNT IS NOT 0 THAT MEAN GOT THE OPRATOR BETWEEN TO BRACKTES SO THAT 
    return false;
}

int main()
{
    string str = "";
    cout << "ENTER STRING: ";
    getline(cin, str);

    bool ans = isValidPrentheses(str);
    ans ? cout << "PRESENTS REDUNDANT BRACKETS" << endl : cout << "REDUNDANT BRACKETS NOT PRESENTS" << endl;
    return 0;
}