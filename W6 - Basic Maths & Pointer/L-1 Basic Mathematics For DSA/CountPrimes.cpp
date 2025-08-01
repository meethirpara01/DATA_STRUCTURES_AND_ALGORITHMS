#include<iostream>
using namespace std; 
// TO SOLVE THIS QUESTIN WE HAVE DIFFRENTE DIFFRENTE APPROCHES
//  1. NAIVE APPROACH - O(n^2)
//  2. SQRT APPROACH - O(n * √n) - MUCH BETTER
//  3. SIEVE OF ERATHOSTHENES APPROCH - O(n * log(log n))  ---> 0 to n 
//  4. SEGMENTED SIEVE APPROCH - O(n * log(log n))  ----> l to h

int NAIVEAPPROACH(int n)
{
    if (n <= 1) return false;
    
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        } 
    }
    return true;
}

int SQRTAPPROACH(int n)
{
    if (n <= 1) return false;
    int sqrtN = sqrt(n);
    
    for (int i = 2; i <= sqrtN; i++)
    {
        if (n % i == 0)
        {
            return false;
        } 
    }
    return true;
}

int SIEVEAPPROCH(int num)
{
    if (num == 0) return 0;

    vector<bool> prime(num, true);
    prime[0] = prime[1] = false;
    int ans = 0;

    for (int i = 2; i < num; i++)
    {
        if (prime[i])
        {
            ans++;

            int j = 2 * i;
            while (j < num)
            {
                prime[j] = false;
                j += i;
            }
        }
    }

    return ans;  
}

int CountPrime(int num)
{
    int c = 0;

    for (int i = 0; i < num; i++)
    {
        if (SQRTAPPROACH(i))
        {
            ++c;
        }
    }
    return c;
}

int main() 
{ 
    int num;
    cout << "Enter Number: " << endl; 
    cin >> num;

    int ans = SIEVEAPPROCH(num);
    cout << "Numbers Of Prime In You Given Number Is: " << ans << endl;

    return 0; 
}