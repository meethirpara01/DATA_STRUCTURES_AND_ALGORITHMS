// MOST MOST IMP

#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a NUmber :" << endl; 
    cin >> num;

    // Method :- 1
    // for (int i = 0; i < num; i++)
    // {
    //     for (int j = 0; j < (2*i + 1); j++)
    //     {
    //         if (j % 2 == 0)
    //             cout << (i + 1) ;
    //         else
    //             cout << "*";
    //     }
    //     cout << endl;
    // }

    // num--;
    // int p = num;
    // for (int i = 0; i < num; i++)
    // {
    //     for (int j = 0; j < (2*num - 2*i - 1); j++)
    //     {
    //         if (j % 2 == 0)
    //             cout << p ;
    //         else
    //             cout << "*";
    //     }
    //     p--;
    //     cout << endl;
    // }

    // Method :- 2
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == i)
                cout << (i + 1);
            else
                cout << (i + 1) << "*" ;
        }
        cout << endl;
    }
    num--;
    int p = num;

    for (int i = 0; i < num; i++)
    {
        for (int j = num; j > i; j--)
        {
            if (j == i + 1)
                cout << p;
            else
                cout << p << "*";
        }
        p--;
        cout << endl;
    }
    
    return 0; 
}