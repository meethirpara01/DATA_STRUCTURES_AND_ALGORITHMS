#include<iostream>
using namespace std; 

string IntegerToRomon(int num)
{
    string romonsymbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "x", "IX", "V", "VI", "I"};
    
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string ans = "";
    for (int i = 0; i < 13; i++)
    {
        while (num > values[i])
        {
            ans += romonsymbol[i];
            num -= values[i];
        }
    }
    return ans;   
}

int main() 
{ 
    int num;
    cout << "Enter Integer Number : "; 
    cin >> num;

    string ans = IntegerToRomon(num);
    cout << "YOUR ROMON NUMBER IS: " << ans << endl;
    return 0; 
}