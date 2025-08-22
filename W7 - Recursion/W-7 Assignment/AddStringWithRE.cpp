#include<iostream>
#include <algorithm>
using namespace std; 
void AddStringRE(string &num1, int p1, string &num2, int p2, int carry, string& ans)
{
    if (p1 < 0 && p2 < 0)
    {
        if (carry != 0)
        {
            ans.push_back(carry + '0');
        }
        return;
    }

    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';

    int csum = n1 + n2 + carry;
    int digit = csum % 10;
    carry = csum / 10;
    ans.push_back(digit + '0');

    AddStringRE(num1, p1 - 1, num2, p2 - 1, carry, ans);
}

void addString(string &num1, int p1, string &num2, int p2, int carry, string& ans)
{
    AddStringRE(num1, p1, num2, p2, carry, ans);
    reverse(ans.begin(), ans.end());
}

int main() 
{ 
    string num1;
    cout << "Enter First String: "; 
    getline(cin, num1);

    string num2;
    cout << "Enter Secoend String: "; 
    getline(cin, num2);

    string ans = "";
    addString(num1, num1.size() - 1, num2, num2.size() - 1, 0, ans);
    cout << "Total Sum In String Formate Is: " << ans << endl;

    return 0; 
}