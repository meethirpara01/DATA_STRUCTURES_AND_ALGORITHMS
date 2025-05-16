#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Number :" << endl; 
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < (num - i - 1); j++)
        {
            cout << " ";
        }
        for (int j = 0; j < (i + 1); j++)
        {
            if (j == 0 || j == i)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= (num - i - 1); j++)
        {
            if (j == 0 || j == (num - i - 1))
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    
    return 0; 
}