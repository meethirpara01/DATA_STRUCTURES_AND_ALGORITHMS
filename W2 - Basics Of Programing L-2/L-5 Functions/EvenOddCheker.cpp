#include<iostream>
using namespace std; 
void EvenOdd(int num)
{
    if (num % 2 == 0)
        cout << "Number Is Even" << endl;
    else
        cout << "Number Is Odd" << endl;
}

int main() 
{
    int num;
    cout << "Ented a Number :" << endl;
    cin >> num;
    EvenOdd(num);

    return 0; 
}