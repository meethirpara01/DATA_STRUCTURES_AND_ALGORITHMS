#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Number :" << endl; 
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = num - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }


    // Mehod :- 2
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i -1 ; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    

    
    
    return 0; 
}