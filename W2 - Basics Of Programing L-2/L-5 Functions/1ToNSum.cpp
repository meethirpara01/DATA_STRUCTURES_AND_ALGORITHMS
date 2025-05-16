#include<iostream>
using namespace std; 
int sum(int num)
{
    int sum = 0;
    for (int i = 0; i <= num; i++)
    {
        sum += i;
    }
    return sum;
}

int main() 
{
    int num;
    cout << "Ented a Number :" << endl;
    cin >> num;
    int ans = sum(num);
    cout << "Total Sum Is : " << ans << endl;

    return 0; 
}