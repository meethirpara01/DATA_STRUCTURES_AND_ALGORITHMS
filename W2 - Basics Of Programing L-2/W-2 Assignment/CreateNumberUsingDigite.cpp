#include<iostream>
#include<cmath>
using namespace std; 

int CreateNumber(int CreateNumber)
{
    int num = 0;
    for (int i = 0; i < CreateNumber; i++)
    {
        int Digit;
        cout << "Enter a Digit : " << endl;
        cin >> Digit;
        num = num * 10 + Digit;
    }
    return num;
}

int main() 
{
    int NumberOfDigit;
    cout << "Enter a Number Of Digit : " << endl;
    cin >> NumberOfDigit;

    int Num = CreateNumber(NumberOfDigit);
    cout << "Created Nubter Is : " << Num << endl;

    return(0); 
}