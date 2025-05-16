#include<iostream>
#include<cmath>
using namespace std; 

int DecimalToBinaryMethod1(int n)
{
    int i = 0;
    int binaryno = 0;
    while (n > 0)
    {
        int bit = n % 2;
        binaryno = bit * pow(10, i++) + binaryno;
        n = n / 2;
    }

    return binaryno;
}

int DecimalToBinaryMethod2(int n)
{
    int i = 0;
    int binaryno = 0;
    while (n > 0)
    {
        int bit = n & 1;
        binaryno = bit * pow(10, i++) + binaryno;
        n = n >> 1;
    }

    return binaryno;
}
int main() 
{
    int num;
    cout << "Enter a Number : " << endl;
    cin >> num;

    int binary = DecimalToBinaryMethod2(num);
    cout << binary << endl;

    return(0); 
}