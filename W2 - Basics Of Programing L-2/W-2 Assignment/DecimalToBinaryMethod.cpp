#include <iostream>
#include <cmath>
using namespace std;

int decialToBinaryConversion(int num)
{
    int binaryNo = 0;
    int i = 0;
    while (num > 0)
    {
        int bit = num % 2;   // AND OPR -> (num & 1)
        binaryNo = bit * pow(10, i++) + binaryNo;
        num = num / 2;  // SHIFT OPR -> num = num >> 1;
    }
    return binaryNo;
}

int main()
{

    int num;
    cout << "Enter NUmber For Binary Conversion: ";
    cin >> num;

    int binaryNo = decialToBinaryConversion(num);
    cout << "Binary Number Is: " << binaryNo << endl;
    return 0;
}