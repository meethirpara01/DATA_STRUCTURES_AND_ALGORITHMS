#include<iostream>
using namespace std; 
void columnWiseAcsses(int arr[][3], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

}
int main() 
{ 
    int arr[3][3]; 
    cout << "Enter Array Elemnet:" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter Element arr[" << i << "]" << "[" << j << "] "; 
            cin >> arr[i][j];
        }
        cout << endl;
    }

    columnWiseAcsses(arr, 3, 3);
    
    return 0; 
}