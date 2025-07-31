// 1. Debug the code. String to Integer

#include<iostream>
using namespace std; 

int mystoi(string s)
{
    int len = s.size();
    double num = 0;
    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    bool negative = s[i] == '-';
    negative == true ? i++ : i;
    while (i < len && s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    num = negative ? -num : num;
    num = (num > INT_MAX) ? INT_MAX : num;
    num = (num < INT_MIN) ? INT_MIN : num;
    return num;
}


 
int main() 
{ 
    string str;
    cout << "Enter String: " << endl; 
    getline(cin, str);

    int ans = mystoi(str);
    cout<< "Converted Integer From String Is: " << ans << endl;

    return 0; 
}



// IN THIS CODE IN ADING NUMBER THEIR IS NOT CONVERT TO INTEGER I'L FIX IT AND IT'S SOLVE. (s[i] - '0')