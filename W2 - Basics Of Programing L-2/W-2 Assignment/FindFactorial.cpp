#include<iostream>
using namespace std; 
long long int FindFactorial(long long int num)
{
    long long int fac = 1;
    for (int i = num; i > 0; i--)
    {
        fac *= i;
    }

    return fac;   
}
int main() 
{ 
    int num;
    cout << "Enter Number : " << endl; 
    cin >> num;

    long long int ans = FindFactorial(num);
    cout << "Your Factorial Is : " << ans << endl;

    return 0; 
}