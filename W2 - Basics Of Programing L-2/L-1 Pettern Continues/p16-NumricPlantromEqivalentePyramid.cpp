#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Number :" << endl; 
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int p = i;
        for (int j = 0; j < num - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }
        for (int j = 0; j < i; j++)
        {
            cout << p;
            p--;
        }
        cout << endl;
    }

    // Mehod :- 2
    for (int i = 0; i < num; i++)
    {
        int p = i;
        for (int j = 0; j < num - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            p = j + 1;
            cout << p;
        }
        for (int r = p; r > 1; r--)
        {
            cout << r - 1;
        }
        cout << endl;
    }
    
    return 0; 
}