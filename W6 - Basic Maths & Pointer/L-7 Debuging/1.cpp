// 1. Debug the code.

#include <iostream>
using namespace std;

void SieveOfEratosthenes(int n) 
{
    vector<bool> prime(n+1, true);
  
    for (int p = 2; p * p <= n; p++) 
    {
        for (int i = p * p; i <= n; i += p) 
            prime[i] = false;  
    } 
  
    for (int p = 0; p <= n; p++) 
        if (prime[p]) 
            cout << p << " "; 
}

int main()
{
    int num;
    cout << "Enter Number: " << endl;
    cin >> num;

    SieveOfEratosthenes(num);
    return 0;
}


// INT HIS CODE PROBLEM IN THIS ASSIGN VALUE TRUE AND FALSE I'l INTTERCHANGE AND IT FIX.
