// 3. Debug the code.
#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;
 
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)  // HERE NOT ADD == 0 I'L SOLVE IT AND IT FIXED.
            return false;
 
    return true;
}

int main()
{
    int num;
    cout << "Enter Number: " << endl;
    cin >> num;

    bool ans = isPrime(num);
    ans ? cout << "Number Is Prime" << endl : cout << "Number Not Prime" << endl; 
    return 0;
}

