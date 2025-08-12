#include<iostream>
using namespace std; 
// FROM N TO 1
void PrintCouting(int n)
{
    // BASE CASE
    // if (n == 0)
    //     return;
    if (n == 1)
    {
        cout << "1 ";
        return;
    }

    //PROCCESING
    cout << n << " ";  // FROM N TO 1

    // RECURSIVE CALL
    PrintCouting(n - 1);

    //PROCCESING
    // cout << n << " ";  // FROM 1 TO N
    return;
}

int main() 
{ 
    int num;
    cout << "Enter An Number To Find Factorial :- "; 
    cin >> num;

    PrintCouting(num);
    cout << endl;
    return 0; 
}