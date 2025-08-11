#include<iostream>
using namespace std; 

int factorial(int n)
{
    // BASE CASE
    if (n == 1)
        return 1;
    if (n == 0)
        return 1;

    //PROCCESING

    // RECURSIVE CALL
    int ans = n *  factorial(n - 1);
    return ans;

    //PROCCESING
}

int main() 
{ 
    int num;
    cout << "Enter An Number To Find Factorial :-"; 
    cin >> num;

    int ans = factorial(num);
    cout << "Your Answer Is :- " << ans << endl;
    return 0; 
}