#include <iostream>
using namespace std;

int x = 2; // GLOBAL VARIABLE

void fun()
{
    int x = 60;
    cout << x << endl; // ~60
    ::x = 40;
    cout << x << endl; // ~60
}

int main()
{
    ::x = 4; // GLOBAL G
    int x = 20;  // LOCAL TO MAIN() FUNCTION
    cout << x << endl; // ~20
    cout << ::x << endl; // ~4

    {
        int x = 50;
        {
            int x = 44;
            cout << x << endl; // ~44
        }
        cout << x << endl; // ~50
        cout << ::x << endl; // ~4
    }
    fun();
    return 0;
}