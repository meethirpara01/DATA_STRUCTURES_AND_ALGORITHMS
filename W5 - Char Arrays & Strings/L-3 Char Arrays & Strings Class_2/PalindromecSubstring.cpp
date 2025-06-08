#include<iostream>
using namespace std; 
// TO SOLVE THIS QUESTION 
// 1. BRUTE FORCE FIND SUBSTRIN(N^2) AND THAN CHECK PALINDROME OR NOT O(N^2) 
// 2. INDEX BASE EVEN OR ODD LANTH SUBSTRIN O(N^2)
int Expand(string str, int i, int j)
{
    int count = 0;
    while (i >= 0 && str[i] == str[j] && j < str.length())
    {
        count++;
        i--;
        j++;
    }
    return count;
}

int PalindromecSubstring(string str)
{
    int totalcount = 0;

    for (int center = 0; center < str.length(); center++)
    {
        // ODD
        int oddAns = Expand(str, center, center);

        //EVEN
        int evenAns = Expand(str, center, center + 1);

        totalcount = totalcount + oddAns + evenAns;
    }
    return totalcount;
}

int main() 
{ 
    string str;
    cout << "Enter String" << endl; 
    getline(cin, str);

    int ans = PalindromecSubstring(str);
    cout << "Total Number Of Pailndromec Substring Is: " << ans << endl; 
    return 0; 
}