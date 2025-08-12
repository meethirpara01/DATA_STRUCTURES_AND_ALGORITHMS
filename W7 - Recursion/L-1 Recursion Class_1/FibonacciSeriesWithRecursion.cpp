#include<iostream>
using namespace std; 

int FindFiboNthTerm(int n)
{
    // BASE CASE
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    //PROCCESING

    // RECURSIVE CALL
    int ans = FindFiboNthTerm(n - 1) + FindFiboNthTerm(n - 2);
    return ans;

    //PROCCESING
}

int main() 
{ 
    int num;
    cout << "Enter An Number To Find Nth Term With Fibonacii Series :- "; 
    cin >> num;

    int ans = FindFiboNthTerm(num);
    cout << "Your Answer Is :- " << ans << endl;
    return 0; 
}