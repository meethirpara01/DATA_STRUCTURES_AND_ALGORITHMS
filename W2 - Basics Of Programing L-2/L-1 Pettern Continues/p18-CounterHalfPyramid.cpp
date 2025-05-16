#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Number :" << endl; 
    cin >> num;

    int count = 1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << count;
            count++;
        }
        cout <<endl;    
    }
    
    return 0; 
}