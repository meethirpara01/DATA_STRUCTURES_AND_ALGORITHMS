#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enterd a number :" << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < (num - i); j++)
        {
            cout << "* ";
        }
        cout << endl;
        
    }
    
    return 0; 
}