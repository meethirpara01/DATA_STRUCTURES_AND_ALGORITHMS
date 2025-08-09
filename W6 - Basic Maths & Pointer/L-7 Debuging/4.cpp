// 4. Debug the code. In this question, if there is no error, remove the bad practices.
#include <iostream>
using namespace std;

int main()
{
    int *ptr = 0;
    int a = 5;
    ptr = &a;
    cout << *ptr << endl;
    return 0;
}


// IT BAD PRECTICE TO DECLARE WILD POINTER I'L SOLVE IT AND IT WILL FIX