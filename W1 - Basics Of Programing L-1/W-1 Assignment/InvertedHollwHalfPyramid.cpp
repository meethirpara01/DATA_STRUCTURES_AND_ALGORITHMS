#include<iostream>
using namespace std; 
 
int main() 
{ 
    int n;
    cout << "Enter a Number :" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= (n - i - 1); j++)
        {
            if (i == 0 || j == 0 || j == (n - i - 1))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            if (i == 0 || j == n-1 || j == i)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    
    return 0; 
}