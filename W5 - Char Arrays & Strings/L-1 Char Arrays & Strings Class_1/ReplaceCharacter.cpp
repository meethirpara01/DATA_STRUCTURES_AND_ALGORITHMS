#include<iostream>
using namespace std; 
void replaceCharacter(char ch[])
{
    int index = 0;
    while (ch[index] != '\0')
    {
        if (ch[index] == ' ')
        {
            ch[index] = '@';
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

    replaceCharacter(ch);
    return 0; 
}