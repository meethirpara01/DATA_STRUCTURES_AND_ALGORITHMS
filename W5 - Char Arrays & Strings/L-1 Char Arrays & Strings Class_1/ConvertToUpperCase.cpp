#include<iostream>
using namespace std; 
void convertToUpperCase(char ch[])
{
    int index = 0;
    while (ch[index] != '\0')
    {
        if (ch[index] >= 'a' && ch[index] <= 'z')
        {
            ch[index] = ch[index] - 'a' + 'A';
        }
        index++;
    }
    cout << "IN UPPER CASE: " << endl << ch << endl;
    
}
int main() 
{ 
    char ch[20];
    cout << "Enter String: " << endl; 
    cin.getline(ch, 20);

    convertToUpperCase(ch);
    return 0; 
}