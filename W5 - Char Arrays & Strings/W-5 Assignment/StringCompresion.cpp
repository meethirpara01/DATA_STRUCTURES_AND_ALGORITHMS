#include<iostream>
using namespace std; 

int StringCompress(string& s)
{
    int index = 0;
    int count = 1;
    char prev = s[0];

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == prev)
            count++;
        else
        {
            s[index++] = prev;
            if (count > 1)
            {
                int start = index;
                while (count)
                {
                    s[index++] = count % 10 + '0';
                    count /= 10;
                }    
                reverse(s.begin() + start, s.begin() + index);
            }
            prev = s[i];
            count = 1;
        }
    }

    s[index++] = prev;
    if (count > 1)
    {
        int start = index;
        while (count)
        {
            s[index++] = count % 10 + '0';
            count /= 10;
        } 
        reverse(s.begin() + start, s.begin() + index);
    }

    return index;
        
}
int main() 
{ 
    string str;
    cout << "Enter String : "; 
    getline(cin, str);

    int ans = StringCompress(str);
    cout << "YOUR INTEGER ANSWER IS: " << str << endl;
    cout << "AND THEIR LENGTH IS: " << ans << endl;
    return 0; 
}