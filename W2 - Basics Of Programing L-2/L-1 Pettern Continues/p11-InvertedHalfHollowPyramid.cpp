#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Numer" << endl; 
    cin >> num;

    // for (int i = 0; i < num; i++)
    // {
    //     for (int j = 0; j <= (num - i - 1); j++)
    //     {
    //         if (i == 0 || j == 0 || j == (num - i - 1))
    //             cout << "* ";
    //         else
    //             cout << "  ";
    //     }
    //     cout << endl;
    // }

    // Method :- 2
    for (int i = 0; i < num; i++)
    {
        for (int j = num; j > i; j--)
        {
            if (i == 0 || j == num || j == i + 1)
                cout << "* ";
            else
                cout << "  ";
            
        }
        cout << endl;
    }
    return 0; 
}