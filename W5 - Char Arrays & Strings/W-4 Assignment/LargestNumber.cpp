#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

static bool mycomp(string a, string b)
{
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2;
    // return a + b > b + a;
}

string LargestNumber(vector<int>& arr)
{
    vector<string> snums;
    for(int n : arr)
    {
        snums.push_back(to_string(n));
    }

    sort(snums.begin(), snums.end(), mycomp);

    // Handle all zeros case
    if(snums[0] == "0") return "0";

    string ans = "";
    for(string str : snums)
    {
        ans += str;
    }

    return ans;
}

int main() 
{
    int size;
    cout << "Enter Size Of Array: ";
    cin >> size;

    vector<int> arr(size);
    for(int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " Element Of Array: ";
        cin >> arr[i];
    }

    string ans = LargestNumber(arr);
    cout << "YOUR LARGEST NUMBER IS: " << ans << endl;
    
    return 0;
}