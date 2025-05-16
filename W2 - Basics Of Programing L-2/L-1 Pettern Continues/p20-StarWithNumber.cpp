#include<iostream>
using namespace std; 
 
int main() 
{ 
    int num;
    cout << "Enter a Number :" << endl; 
    cin >> num;


    // Mehod :- 1 This One Is Better Aproch 
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j <= 2*num-i-2; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < (2*i + 1); j++)
        {
            if (j % 2 == 0)
                cout << i + 1;
            else
                cout << "*";
        }
        for (int j = 0; j <= 2*num-i-2; j++)
        {
            cout << "*";
        }
        cout <<endl;    
    }

    // Mehod :- 2 By Lakshay
    for (int i = 0; i < num; i++)
    {
        int start_num_index = 8 - i;
        int num = i + 1;
        int count_num = num;

        for (int j = 0; j < 17; j++)
        {
            if (j == start_num_index && count_num > 0)
            {
                cout << num;
                start_num_index += 2;
                count_num--;
            }
            else
                cout << "*";
        }
        cout << endl;
    }
    return 0; 
}