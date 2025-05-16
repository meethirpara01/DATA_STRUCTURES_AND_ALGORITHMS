#include<iostream>
using namespace std; 
bool EvenOddBitwise(int num)
{
    if((num ^ 1) == (num + 1))  // if((num & 1) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
int main() 
{ 
    int num;
    cout << "Enter Number : " << endl; 
    cin >> num;

    int ans = EvenOddBitwise(num);
    (ans) ? cout << "Numbers Is Even" << endl : cout << "Number Is Odd" << endl ;


    return 0; 
}