#include <iostream>
using namespace std;

class Info
{
    public:
        char val;
        int count;

        Info(char ch, int cnt)
        {
            this->val = ch;
            this->count = cnt;
        }
};

class compare
{
    public:
        bool operator()(Info a, Info b)
        {
            return a.count < b.count;
        }
};

string recognizeString(string s)
{
    int freq[26] = {0};

    // COUNT FREQUENCY OF ALL CHARACTERS IN STRING
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        freq[ch - 'a']++;
    }

    // PUSH ALL CHARACTERS IN MAXHEAP
    priority_queue<Info, vector<Info>, compare> maxHeap;

    // PUSH ALL CHARACTERS IN MAXHEAP, WHERE FREQUENCY IS > 0
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            // Info temp = new Info(i + 'a', freq[i]);
            Info temp(i + 'a', freq[i]);
            maxHeap.push(temp);
        }
    }

    string ans = "";

    while (maxHeap.size() > 1)
    {
        Info first = maxHeap.top();
        maxHeap.pop();
        
        Info second = maxHeap.top();
        maxHeap.pop();

        ans.push_back(first.val);
        first.count--;

        ans.push_back(second.val);
        second.count--;
        
        if (first.count > 0)
        {
            maxHeap.push(first);
        }

        if (second.count > 0)
        {
            maxHeap.push(second);
        }
    }

    // IF 1 ELEMENT BACHA H, TOH ALAG SE HANDLE KARO 
    if (maxHeap.size() == 1)
    {
        Info first = maxHeap.top();
        maxHeap.pop();

        ans.push_back(first.val);
        first.count--;

        if (first.count != 0)
        {
            return "";
        }
    }

    return ans; 
}

int main()
{
    string str;
    cout << "ENTER STRING: ";
    cin >> str;

    string ans = recognizeString(str);
    if (ans != "")
    {
        cout << "REARRANGEMENT IS POSSIBLE: " << endl;
        cout << ans << endl;
    }
    else 
    {
        cout << "REARRANGEMENT IS NOT POSSIBLE" << endl;
    }
    return 0;
}