#include<iostream>
using namespace std; 
string mainstr;
bool compare(char char1, char char2)
{
    return (mainstr.find(char1) < mainstr.find(char2));
}

int main() 
{ 
    string str;
    cout << "Enter a String: " << endl; 
    getline(cin, str);

    string order;
    cout << "Enter Order Of String: " << endl; 
    getline(cin, order);

    mainstr = order;
    sort(str.begin(), str.end(), compare);
    cout << "Your Sorted String Is: " << str << endl;
    return 0; 
}