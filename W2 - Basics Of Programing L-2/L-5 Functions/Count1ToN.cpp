#include<iostream>
using namespace std; 
int count(int num)
{
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        count++; 
    }

    return count;
}

int main() 
{
    int num;
    cout << "Ented a Number :" << endl;
    cin >> num;
    int ans = count(num);
    cout << "counter value is :" << ans <<endl;
    return 0; 
}