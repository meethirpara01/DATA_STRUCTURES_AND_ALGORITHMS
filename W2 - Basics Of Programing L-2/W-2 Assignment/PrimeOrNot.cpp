#include<iostream>
using namespace std; 
bool PRIME(int num)
{
    if (num == 0 || num == 1)
    {
        cout << "0 AND 1 NOT PRIME" << endl;
        return false;
    }  
    else
    {
        for (int i = 2; i <= sqrt(num); i++)
        {
            if ((num & 1) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main() 
{
    int num;
    cout << "Ented a Number :" << endl;
    cin >> num;
    int ans = PRIME(num);
    ans == (true) ? cout << "NUMBER IS PRIME" : cout << "NUMBRE NOT PRIME";

    return 0; 
}