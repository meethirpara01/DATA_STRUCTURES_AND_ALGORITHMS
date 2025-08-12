#include<iostream>
using namespace std; 

int PowerOf2(int n)
{
    // BASE CASE
    if (n == 0)
        return 1;

    //PROCCESING

    // RECURSIVE CALL
    int ans = 2 * PowerOf2(n - 1);
    return ans;

    //PROCCESING
}

int PowerOf2M2(int n)
{
    // BASE CASE
    if (n == 0)
        return 1;

    //PROCCESING

    // RECURSIVE CALL
    int RecursionKaAns = PowerOf2M2(n - 1);

    //PROCCESING
    int finalAns = 2 * RecursionKaAns;
    return finalAns;
}

int main() 
{ 
    int num;
    cout << "Enter An Number To Find Power Of 2 For This Number :- "; 
    cin >> num;

    int ans = PowerOf2M2(num);
    cout << "Your Answer Is :- " << ans << endl;
    return 0; 
}