#include<iostream>
using namespace std; 
int Reverse(int num)
{
    int ans = 0;
    bool isNeg = false;
    if (num <= INT_MIN)
        return 0;
    
    if (num < 0)
    {
        isNeg = true;
        num = -num;
    }

    while (num > 0)
    {
        if (ans > INT_MAX / 10)
            return 0;
        int rem = num % 10;
        ans = (ans * 10) + rem;
        num = num / 10;
    }

    return (isNeg) ? -ans : ans;   
}
int main() 
{ 
    int num;
    cout << "Enter Number : " << endl; 
    cin >> num;
    cout << num << endl; 

    int ans = Reverse(num);
    cout << "Reverse Number IS : " << ans << endl;


    return 0; 
}