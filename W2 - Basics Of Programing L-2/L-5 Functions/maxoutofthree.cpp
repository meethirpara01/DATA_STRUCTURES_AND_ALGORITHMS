#include<iostream>
using namespace std; 
void max(int num1,int num2,int num3)
{
    if (num1 > num2 && num1 > num3)
    {
        cout << "Your Enterd First Number Is Large" << endl;
    }
    else
    {
        if (num2 > num1 && num2 > num3)
        {
            cout << "Your Enterd Seconde Number Is Large" << endl;
        }
        else
        {
            cout << "Your Enterd Thred Number Is Large" << endl;
        }  
    }
}

int PreDefine(int num1,int num2,int num3)
{
    int ans = max(num1, num2);
    int FainalAns = max(ans, num3);

    return FainalAns;
}

int main() 
{
    int num1, num2, num3;
    cout << "Ented Three Numbers :" << endl;
    cin >> num1 >> num2 >> num3;
    max(num1, num2, num3);

    int ans = PreDefine(num1, num2, num3);
    cout << "Maximum Number Is : " << ans << endl;
    return 0; 
}