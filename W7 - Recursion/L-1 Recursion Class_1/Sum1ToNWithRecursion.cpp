#include<iostream>
using namespace std; 

int FindSumFrom1ToN(int n)
{
    // BASE CASE
    if (n == 1)
        return 1;

    //PROCCESING

    // RECURSIVE CALL
    int ans = n + FindSumFrom1ToN(n - 1);
    return ans;

    //PROCCESING
}

int FindSumFrom1ToNM2(int n)
{
    // BASE CASE
    if (n == 1)
        return 1;

    //PROCCESING

    // RECURSIVE CALL
    int RecursionKaAns = FindSumFrom1ToNM2(n - 1);

    //PROCCESING
    int finalAns = n + RecursionKaAns;
    return finalAns;
}

int main() 
{ 
    int num;
    cout << "Enter An Number To Find Sum :- "; 
    cin >> num;

    int ans = FindSumFrom1ToN(num);
    cout << "Your Answer Is :- " << ans << endl;
    return 0; 
}