#include<iostream>
#include<cmath>
using namespace std; 

int CountAllSetBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        int bit = (num & 1);
        if (bit)
            count++;
        num >>= 1; 
    }

    return count;
}

int main() 
{
    int num;
    cout << "Enter a Number : " << endl;
    cin >> num;

    int Conut = CountAllSetBits(num);
    cout << "IN THIS NUMBER TOTAL SET BIT IS : " << Conut << endl;

    return(0); 
}