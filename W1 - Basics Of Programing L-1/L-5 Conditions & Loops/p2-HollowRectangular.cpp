#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Number :" << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == 0 || j == 0 || i == (num - 1) || j == (num - 1))
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    return 0; 
}