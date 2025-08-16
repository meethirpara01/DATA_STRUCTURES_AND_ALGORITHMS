#include<iostream>
using namespace std; 

void FindSubsqeuecne(string str, string output, int index)
{
    if (index >= str.length())
    {
        // ANS jo h, vo output string me build ho chuka hai 
        // print karo
        cout << output << endl;
        return; 
    }

    char ch = str[index];

    // EXCLUDE
    FindSubsqeuecne(str, output, index + 1);

    // INCLUDE
    output.push_back(ch);
    FindSubsqeuecne(str, output, index + 1);
}

int main() 
{ 
    string str;
    cout << "Enter An String: "; 
    cin >> str;

    string output = "";
    FindSubsqeuecne(str, output, 0);
    return 0; 
}