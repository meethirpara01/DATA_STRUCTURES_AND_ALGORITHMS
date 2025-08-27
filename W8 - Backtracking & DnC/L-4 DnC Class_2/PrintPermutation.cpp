#include<iostream>
using namespace std; 

void printPermutation(string str, int index)
{
    // BASE CASE
    if (index >= str.length())
    {
        cout << str << " ";
        return;
    }

    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);\
        printPermutation(str, index + 1);
    }
}\
int main() 
{ 
    string str;
    cout << "Enter String: "; 
    getline(cin, str);

    printPermutation(str, 0);
    return 0; 
}