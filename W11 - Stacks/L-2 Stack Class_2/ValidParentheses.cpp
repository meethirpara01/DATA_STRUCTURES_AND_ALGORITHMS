#include <iostream>
#include<stack>
using namespace std;

bool isValidPrentheses(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            // FOR OPEN BRACKETS -> JUST PUSH
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                // CLOSEING BRACKETS
                if (ch == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else if (ch == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else if (ch == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (st.size() == 0)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    string str = "";
    cout << "ENTER STRING: ";
    getline(cin, str);

    bool ans = isValidPrentheses(str);
    ans ? cout << "STRING IS VALID PARENTHESES" << endl : cout << "STRING IS NOT VALID PARENTHESES" << endl;
    return 0;
}