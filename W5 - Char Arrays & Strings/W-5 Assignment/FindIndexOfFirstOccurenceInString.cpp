#include<iostream>
using namespace std; 

int FindIndexOfOccurenceInString(string haystack, string needle)
{
    int m = haystack.size();
    int n = needle.size();
    
    // Handle edge cases
    if (n > m) return -1;
    if (n == 0) return 0;
    
    // Search for needle in haystack
    for (int i = 0; i <= m - n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                break;
            }
        }
        // If we completed the inner loop, we found a match
        if (j - 1 == n - 1)
        {
            return i;
        }
    }
    return -1;
}
 
int main() 
{ 
    string haystack;
    cout << "Enter Haystack String: "; 
    getline(cin, haystack);

    string needle;
    cout << "Enter Needle String: "; 
    getline(cin, needle);

    int index = FindIndexOfOccurenceInString(haystack, needle);
    
    if (index != -1)
        cout << "First occurrence found at index: " << index << endl;
    else
        cout << "Needle not found in haystack" << endl;

    return 0; 
}