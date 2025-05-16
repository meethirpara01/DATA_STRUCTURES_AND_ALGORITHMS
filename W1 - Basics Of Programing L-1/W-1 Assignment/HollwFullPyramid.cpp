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
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i || i == 0 || i == n - 1)
                cout << "* ";
            else
                cout << "  ";
            
        }
        cout << endl;
    }

    return 0; 
}