#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Numer" << endl; 
    cin >> num;

    
    for (int i = 0; i < num; i++)
    {
        int count = i + 1;
        for (int j = 0; j < (num - i); j++)
        {
            if (j == 0 || j == (num - i -1) || i == 0 || i == num - 1)
            {
                cout << count;
            }
            else
            {
                cout << " "; 
            }
            count++;
        }
        cout << endl; 
    }

    // Mehod :- 2
    for (int i = 0; i < num; i++)
    {
        int count = i + 1;
        for (int j = num; j > i; j--)
        {
            if (j == num || j == i + 1 || i == 0 || i == num - 1)
            {
                cout << count;
            }
            else
            {
                cout << " "; 
            }
            count++;
        }
        cout << endl; 
    }

    
    return 0; 
}