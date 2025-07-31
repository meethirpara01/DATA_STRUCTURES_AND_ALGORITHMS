// 6. Debug the code.
/*
Test Case:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
*/

#include <iostream>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    string result = "";
    int i = 0, j = 0;

    while (i < m || j < n)
    {
        if (i < m)
        {
            result.push_back(word1[i++]);
        }
        else if (j < n)
        {
            result.push_back(word2[j++]);
        }
    }

    return result;
}

int main()
{
    string str1;
    cout << "Enter String 1 " << endl; 
    getline(cin, str1);

    string str2;
    cout << "Enter String 2: " << endl; 
    getline(cin, str2);

    string ans = mergeAlternately(str1, str2);
    cout<< "Your Merge String Are: " << ans << endl;

    return 0;
}

// HERE IN THIS CODE MISTAKE IS IN THIS LINE else if (j < n) I'L ONLY USE IF AND IT FIX.