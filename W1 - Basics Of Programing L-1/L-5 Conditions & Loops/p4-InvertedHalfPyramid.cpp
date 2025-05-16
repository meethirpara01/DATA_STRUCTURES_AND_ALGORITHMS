#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Number :" << endl;
    cin >> num;

    // Mehod - 1
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // Mehod - 2
    for (int i = 0; i < num; i++)
    {
        for (int j = num - 1; j >= i; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0; 
}