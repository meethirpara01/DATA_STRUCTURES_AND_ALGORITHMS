#include<iostream>
#include<cmath>
using namespace std; 

int setAllKthHBits(int num, int k)
{
    // int mask = (1 << k);
    // int ans = (num | mask);

    return num | (1 << k);
}

int main() 
{
    int num;
    cout << "Enter a Number : " << endl;
    cin >> num;

    int k;
    cout << "Enter a Kth Bit : " << endl;
    cin >> k;

    int ans = setAllKthHBits(num, k);
    cout << "OUR ANSWER IS : " << ans << endl;

    return(0); 
}