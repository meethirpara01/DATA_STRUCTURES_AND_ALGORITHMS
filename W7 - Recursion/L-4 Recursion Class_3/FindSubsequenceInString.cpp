#include<iostream>
using namespace std; 

void FindSubsqeuecne(string str, string output, int index, vector<string>& ans)
{
    if (index >= str.length())
    {
        // ANS jo h, vo output string me build ho chuka hai 
        // print karo
        // cout << "--> " << output << endl;
        ans.push_back(output);
        return; 
    }

    char ch = str[index];

    // EXCLUDE
    FindSubsqeuecne(str, output, index + 1, ans);

    // INCLUDE
    output.push_back(ch);
    FindSubsqeuecne(str, output, index + 1, ans);

    // AND IF WE WRITE INCLUDE FIRST THAN IN EXCLUDE PART WE NEED TO POP_BACK IN OUTPUT STRING FIRST AND THAN CALL!
}

int main() 
{ 
    string str;
    cout << "Enter An String: "; 
    cin >> str;

    string output = "";
    vector<string> ans;
    FindSubsqeuecne(str, output, 0, ans);

    cout << "Printing Subseqences Of An String You Given: " << endl;
    for(auto seq: ans)
    {
        cout << "--> " << seq << endl;
    }
    return 0; 
}