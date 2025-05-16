#include<iostream>
#include<cmath>
using namespace std; 

int BinaryDecimalToMethod1(int n)
{
    int i = 0;
    int digit = 0;
    // int sum = 0;
    while (n > 0)
    {
        int bit = n % 2;     // It's Intersting
        digit = bit * pow(2, i++) + digit;
        // sum = sum + digit;
        n = n / 10;
    }
    return digit;
}

int BinaryDecimalToMethod2(int n)
{
    int i = 0;
    int digit = 0;
    while (n > 0)
    {
        int bit = n & 1;
        digit = bit * pow(2, i++) + digit;
        n = n >> 1;
    }

    return digit;
}
int main() 
{
    int num;
    cout << "Enter a Number : " << endl;
    cin >> num;

    int binary = BinaryDecimalToMethod1(num);
    cout << binary << endl;

    return(0); 
}