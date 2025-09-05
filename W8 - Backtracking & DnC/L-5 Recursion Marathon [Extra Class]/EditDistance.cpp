#include <iostream>
using namespace std;
int editstance(string& w1, string& w2, int i, int j)
{
    // BASE CASE
    if (i >= w1.length())
    {
        // WORD1 VALI STRING END HO GAI
        // IT MEAN WORD1 SORTER THAN WORD2
        return w2.length() - j;
    }
    
    if (j >= w2.length())
    {
        // WORD2 VALI STRING END HO GAI
        // IT MEAN WORD2 SORTER THAN WORD1
        return w1.length() - i;
    }

    int ans = 0;
    if (w1[i] == w2[j])
    {
        // MATCH
        ans = 0 + editstance(w1, w2, i + 1, j + 1);
    }
    else
    {
        // NOT MATCH
        // PERFORM THE OPRATION
        // INSERT
        int option1 = 1 + editstance(w1, w2, i, j + 1);
        // REMOVE
        int option2 = 1 + editstance(w1, w2, i + 1, j);
        // REPLACE
        int option3 = 1 + editstance(w1, w2, i + 1, j + 1);
        ans = min(option1, min(option2, option3));
    }

    return ans;   
}
    
int main()
{
    string str1;
    cout << "Enter String One: ";
    cin >> str1;
    
    string str2;
    cout << "Enter String Scoend: ";
    cin >> str2;

    int i = 0;
    int j =  0;
    int ans = editstance(str1, str2, i, j);
    cout << "Minimum Opation Requiare Is: " << ans << endl;  
    return 0;
}