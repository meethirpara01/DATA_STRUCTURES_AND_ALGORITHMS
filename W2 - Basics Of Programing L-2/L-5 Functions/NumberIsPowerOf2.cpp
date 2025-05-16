#include<iostream>
using namespace std; 

bool NumberisPowerOfTwo(unsigned int x)
{
    return (!(x & (x - 1)));
}
bool EvenOdd(int n)
{
    if ((n & 1) == 1)
    {
        return 0;
    }
    return 1;
}
int main() 
{ 
    unsigned int num;
    cin >> num;
    int ans = NumberisPowerOfTwo(num); 
    ans == (true) ? cout << "PowerOfTwo" << endl : cout << "NotPowerTwo" << endl;

    int n = 10;
    EvenOdd(n);
    EvenOdd(n) ? cout << "Even" << endl : cout << "Odd" << endl;
    
    return 0; 
}