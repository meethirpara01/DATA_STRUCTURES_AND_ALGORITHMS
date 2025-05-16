#include<iostream>
using namespace std; 

vector<int> FindFectorialOfLargeNumber(int num)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int x = ans[j] * i + carry;
            ans[j] = x % 10;
            carry = x / 10;
        }

        while (carry)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }   
    }

    reverse(ans.begin(), ans.end());
    return ans;  
}
int main() 
{ 
    int num;
    cout << "Enter Number: ";
    cin >> num;
    

    vector<int> ans = FindFectorialOfLargeNumber(num);
    for (auto i : ans)
    {
        cout << i;
    }
    cout << endl;
    
    return 0; 
}