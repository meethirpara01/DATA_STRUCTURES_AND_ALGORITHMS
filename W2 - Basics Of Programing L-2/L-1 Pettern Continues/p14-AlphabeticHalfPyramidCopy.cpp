#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Numer" << endl; 
    cin >> num;

    
    // for (int i = 0; i < num; i++)
    // {
    //     char alpha = 'A';
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << alpha;
    //         alpha++;
    //     }
    //     for (char ch = alpha - 2; ch >= 'A'; ch--)
    //     {
    //         cout << ch;
    //     }
    //     cout << endl; 
    // }

    // Method :- 2
    // for (int i = 0; i < num; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         int number = j + 1;
    //         char ch = number + 'A' - 1;
    //         cout << ch;
    //     }
    //     for (int j = i; j > 0; j--)
    //     {
    //         int number = j + 1;
    //         char ch = number + 'A' - 2;
    //         cout << ch;
    //     }
    //     cout << endl; 
    // }

    // Method :- 3
    for (int i = 0; i < num; i++)
    {
        char ch;
        for (int j = 0; j <= i; j++)
        {
            int number = j + 1;
            ch = number + 'A' - 1;
            cout << ch;
        }
        for (char alpha = ch; alpha > 'A'; )
        {
            alpha = alpha - 1;
            cout << alpha;
        }
        cout << endl; 
    }

    // Mehod :- 4
    // for (int i = 0; i < num; i++)
    // {
    //     char alpha = 'A';
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << alpha;
    //         alpha++;
    //     }
    //     alpha = alpha - 2;
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << alpha;
    //         alpha++;
    //     }
    //     cout << endl; 
    // }
    
    return 0; 
}