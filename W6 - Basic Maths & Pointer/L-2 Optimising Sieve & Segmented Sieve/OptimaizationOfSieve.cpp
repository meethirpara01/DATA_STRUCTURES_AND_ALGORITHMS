#include<iostream>
using namespace std; 
// TO SOLVE THIS QUESTIN WE HAVE DIFFRENTE DIFFRENTE APPROCHES
//  1. Inner Loop Optimaization
//  2. Outer Loop Optimaization O(n log(log n))

int SIEVEAPPROCHOPTIMAIZATIONONE(int num)
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

            int j = i * i;
            while (j < num)
            {
                prime[j] = false;
                j += i;
            }
        }
    }
    return ans;  
}

int SIEVEAPPROCHOPTIMAIZATIONTWO(int num)
{
    if (num == 0) return 0;

    vector<bool> prime(num, true);
    prime[0] = prime[1] = false;
    int ans = 0;
    int sqrtN = sqrt(num);

    for (int i = 2; i <= sqrtN; i++) // WE CAN ALSO WRITE ---->  for (int i = 2; i * i <= num; i++)
    {
        if (prime[i])
        {
            int j = i * i;
            while (j <= num)
            {
                prime[j] = false;
                j += i;
            }
        }
    }

    for (int i = 2; i <= num; i++)
    {
        if (prime[i]) ans++;
    }
    return ans;  
}


int main() 
{ 
    int num;
    cout << "Enter Number: " << endl; 
    cin >> num;

    int ans = SIEVEAPPROCHOPTIMAIZATIONTWO(num);
    cout << "Numbers Of Prime In You Given Number Is: " << ans << endl;

    return 0; 
}