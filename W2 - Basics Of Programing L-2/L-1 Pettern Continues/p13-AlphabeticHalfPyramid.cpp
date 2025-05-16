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
    //     cout << endl; 
    // }

    // Method :- 2
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int number = j + 1;
            char ch = number + 'A' - 1;
            cout << ch;
        }
        cout << endl; 
    }
    
    return 0; 
}