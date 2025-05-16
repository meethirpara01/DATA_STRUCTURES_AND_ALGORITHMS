#include<iostream>
#include<cmath>
using namespace std; 

void PrintDigit(int num)
{
    while (num > 0)
    {
        int OnePlaceDigit = num % 10;
        cout << "Digti :" << OnePlaceDigit << endl;
        num /= 10;
    }
    
}

int main() 
{
    int Number;
    cout << "Enter a Number : " << endl;
    cin >> Number;

    PrintDigit(Number);

    return(0); 
}