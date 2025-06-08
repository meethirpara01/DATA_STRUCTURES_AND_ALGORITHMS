#include<iostream>
using namespace std; 
// TO SOLVE THIS QUESTION 
// 1. BRUTE FORCE METHOD O(N^2) 
// 2. INDEX BASE APPROCH O(N) 
// 3. NEW TEMP STRING O(N) 

string RemoveDuplicatesIndexign(string str)
{
    int index = 0;
    while (index < str.length() && str.length() > 1)
    {
        if (str[index] == str[index + 1])
        {
            str.erase(index, 2);
            index = 0;
        } 
        else
            index++;
    }
    return str;
}

string RemoveDuplicatesTempString(string str)
{
    string temp = "";
    int index = 0;

    while (index < str.length())
    {
        if (temp.length() > 0 && temp[temp.length() - 1] == str[index])
            temp.pop_back();
        else
            temp.push_back(str[index]);  
        index++;
    }
    return temp;
}

int main() 
{ 
    string str;
    cout << "Enter String" << endl; 
    getline(cin, str);

    string ans = RemoveDuplicatesIndexign(str);
    cout<< "Your Answer Is: " << ans << endl;
    return 0; 
}