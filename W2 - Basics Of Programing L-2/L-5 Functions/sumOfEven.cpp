#include<iostream>
using namespace std; 
int Evensum(int num)
{
    int sum = 0;
    for (int i = 2; i <= num; i += 2)
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
    int ans = Evensum(num);
    cout << "Total Sum Of Even Number Is : " << ans << endl;

    return 0; 
}