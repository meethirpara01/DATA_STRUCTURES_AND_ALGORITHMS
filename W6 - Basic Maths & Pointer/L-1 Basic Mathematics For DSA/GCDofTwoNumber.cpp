#include<iostream>
using namespace std; 

int findGCD(int A, int B)
{
    if (A == 0) return B;
    if (B == 0) return A;
    
    while (A > 0 && B > 0)
    {
        if (A > B)
            A = A - B;
        else
            B = B - A;
    }

    return A == 0 ? B : A;
}

int main() 
{ 
    int num1, num2;
    cout << "Enter Number One: "; 
    cin >> num1;
    cout << "Enter Number Two: "; 
    cin >> num2;

    int ans = findGCD(num1, num2);
    cout << "Your GCD Of Your Given Numbers Is: " << ans << endl;
    cout << "AND ALSO WE CAN FIND LCM WITH HELP OF THIS GCD"<< endl;
    cout << "AND YOUR LCM FOR THSH NUMBER IS: " << (num1 * num2) / ans << endl;
    return 0; 
}