// 3. Debug the code. Add two binary numbers.
#include <iostream>
using namespace std;

string addBinary(string a, string b)
{
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        if (i > 0)
            carry += a[--i] - '0';
        if (j > 0)
            carry += b[--j] - '0';
        ans += carry % 2 + '0';
        carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
}

int main()
{
    string num1;
    cout << "Enter Number One:" << endl;
    getline(cin, num1);

    string num2;
    cout << "Enter Number Two:" << endl;
    getline(cin, num2);

    string ans = addBinary(num1, num2);
    cout << "Your Sum Of Binary Numbers Is: " << ans << endl;

    return 0;
}


// INTHIS CODE PROBLEM IN DICREMENT AND DEVIDE I'L FIX IT AND ALL SET.  carry += a[--i]  --  '0';  --  carry += b[--j] - '0';  --  carry /= 2;
