// 5. Debug the code. You have to make value of *q = 6.
#include <iostream>
using namespace std;

int main(){
    int p = 5;
    int const *q = &p;
    *q++; /// TO MAKE P = 6 REPLCE THIS LINE WITH P++ THIS
    cout << p << endl;
    return 0;
}

// PROBLEMIN THIS CODE IS IN INCREMENTE I'L FIX IT.   t[i] = vowel[++j];