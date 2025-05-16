#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Number :" << endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++) // j < i + 1;
        {
            cout << "* ";
        }
        cout << endl;
    }

    
    return 0; 
}