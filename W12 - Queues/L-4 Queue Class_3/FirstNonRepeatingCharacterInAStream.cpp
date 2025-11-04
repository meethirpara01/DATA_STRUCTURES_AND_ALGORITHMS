#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeatingCharacterInAStream(string str)
{
    queue<char> q;
    int freq[26] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        int ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);

        // FIND THE ANSWER
        while (!q.empty())
        {
            char fronCharacter = q.front();
            if (freq[fronCharacter - 'a'] > 1)
            {
                // FREQUANCY IS GREATER THAN TO 1 THAT MEAN THAT CHARACTER IS NOT ANSWER
                q.pop();
            }
            else // FREQUANCY IS EQUALE TO 1 AND THAT'S THE ANSWER
            {
                cout << fronCharacter << "->";
                break;
            }
        }
    }

    if (q.empty())
    {
        cout << "#" << "->";
    }
}

int main()
{
    string str;
    cout << "Enter An String: ";
    getline(cin, str);

    cout << "FIRST NON-REPEATING CHARACTER IN A SREAME IS: " << endl;
    firstNonRepeatingCharacterInAStream(str);
    return 0;
}