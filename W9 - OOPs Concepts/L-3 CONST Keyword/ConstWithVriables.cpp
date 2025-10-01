#include<iostream>
using namespace std;

int main()
{
    // const int x = 5; // X IS CONSTENT 
    // Initialization Can Be Done
    // BUT WE CAN'T RE-ASIGN A VALUE
    // x = 10;
    // cout << x << endl;

    // 2. CONST WITH POINTER
    // const int *a = new int(2); // CONST DATA, NON-CONST POINTER
    // // int const *a = new int(2); // I ALSO CAN WRITE AS
    // // *a = 2; // I CAN'T DO THAT
    // cout << *a << endl;
    // int b = 5;
    // a = &b;
    // cout << *a << endl;

    // 3. CONST POINETR, NON-CONST DATA
    // int *const a = new int(2);
    // cout << *a << endl;
    // *a = 20;
    // cout << a << endl;
    // int b = 50;
    // a = &b; // I CAN'T DO THAT

    // 4. CONST POINTER, CONST DATA
    const int *const a = new int(2);
    cout << *a << endl;

    return 0;
}