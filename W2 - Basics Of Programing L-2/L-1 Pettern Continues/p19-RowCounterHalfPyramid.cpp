#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Number :" << endl; 
    cin >> num;

    
    for (int i = 0; i < num; i++)
    {
        int count = i + 1;
        for (int j = 0; j <= i; j++)
        {
            cout << count++;
        }
        cout <<endl;    
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = i; j <= i * 2;)
        {
            cout << ++j;
        }
        cout <<endl;    
    }
    
    return 0; 
}