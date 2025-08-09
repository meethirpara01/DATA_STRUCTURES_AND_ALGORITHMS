// 6. Debug the code.  Output should be 101 and 104.

#include <iostream>
using namespace std;

int main()
{
    int a = 100;
    int *p = &a;
    int **q = &p;
    int b = ++(**q) + 4; // TO GET THIS OUTPUT REPLCE THIS LINE WITH int b = (**q)++ + 4; THIS AND IT FIX.
    cout << a << " " << b << endl;
}

