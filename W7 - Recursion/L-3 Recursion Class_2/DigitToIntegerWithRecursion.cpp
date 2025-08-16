#include<iostream>
using namespace std; 

void DigitToInteger(vector<int> Digit, int size, int index, int &ans)
{
    if (index >= size)
        return;

    ans = ans * 10 + Digit[index];

    DigitToInteger(Digit, size, index + 1, ans);
}

int main() 
{ 
    int size;
    cout << "Enter Size Of Array : ";
    cin >> size;

    vector<int> Digit;
    for (int i = 0; i < size; i++)
    {
        int input;
        cout << "Enter " << i + 1 << " Element Of Array : ";
        cin >> input;
        Digit.push_back(input);
    }

    int ans = 0;
    DigitToInteger(Digit, size, 0, ans);
    cout << "Converted Integer Is: " << ans << endl;
    
    return 0; 
}