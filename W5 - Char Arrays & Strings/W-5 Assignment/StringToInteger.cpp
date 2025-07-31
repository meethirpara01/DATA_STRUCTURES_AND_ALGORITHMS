#include<iostream>
using namespace std; 

int StringToInteger(string s)
{
    int num = 0;
    int i = 0;
    int sign = 1;

    while (s[i] == ' ')
        i++;

    if (i < s.size() && (s[i] == '-' || s[i] == '+'))
    {
        sign = s[i] =='+' ? 1 : -1;
        i++;
    }

    while (i < s.size() && isdigit(s[i]))
    {
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7'))
        {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        
        num = num * 10 + (s[i] - '0');
        i++;
    }
    return num * sign;
}

int main() 
{ 
    string str;
    cout << "Enter String : "; 
    getline(cin, str);

    int ans = StringToInteger(str);
    cout << "YOUR INTEGER ANSWER IS: " << ans << endl;
    return 0; 
}