#include<iostream>
using namespace std; 

string ReorganizeString(string& str)
{
    int hash[26] = {0};

    for (int i = 0; i < str.size(); i++)
    {
        hash[str[i] - 'a']++;
    }

    char max_freq_char;
    int max_freq = INT_MIN;

    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max_freq) 
        {
            max_freq = hash[i];
            max_freq_char = i +  'a';
        }
    }

    int index = 0;
    while (max_freq > 0 && index < str.size())
    {
        str[index] = max_freq_char;
        max_freq--;
        index += 2;
    }

    if (max_freq != 0)
    {
        return "";
    }

    hash[max_freq_char - 'a'] = 0;
    

    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index >= str.size() ? 1 : index;
            str[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }

    return str;
}

int main() 
{ 
    string str;
    cout << "Enter String: "; 
    getline(cin, str);

    string ans = ReorganizeString(str);
    cout << "Your Reorganize String Is: " << ans << endl;
    return 0; 
}