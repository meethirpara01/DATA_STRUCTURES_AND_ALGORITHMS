#include<iostream>
using namespace std; 

int SlowExponentiation(int A, int B)
{
    int ans = 1;
    for (int i = 0; i < B; i++)
        ans *= A;
    return ans;
} // O(B)

int FastExponentiation(int A, int B)
{
    int ans = 1;
    while (B > 0)
    {
        if (B & 1)
            ans = ans * A;
        A = A * A;
        B >>= 1;
    }
    return ans;
} // O(log(B))

long long int FastExponentiationForLargeNumber(long long int A, long long int B, long long int M)
{
    long long int ans = 1;
    while (B > 0)
    {
        if (B & 1)
            ans = (ans * A) % M;
        A = (A * A) % M;
        B >>= 1;
    }
    return ans % M;
} // O(B)

int main() 
{ 
    int num1, num2;
    cout << "Enter Number One: "; 
    cin >> num1;
    cout << "Enter Number Two: "; 
    cin >> num2;

    int ans = FastExponentiation(num1, num2);
    cout << "Your FAST EXPONENTIATION Is: " << ans << endl;
    return 0; 
}