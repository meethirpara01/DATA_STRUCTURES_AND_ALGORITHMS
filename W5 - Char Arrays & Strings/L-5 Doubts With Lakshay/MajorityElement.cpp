#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

int FindMajorityElement(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    return arr[(0 + arr.size() - 1) / 2];
}

int main() 
{ 
    int size;
    cout << "Enter Size Array: "; 
    cin >> size;

    vector<int> arr;
    for (int i = 0; i < size; i++)
    {
        int input;
        cout << "Enter Array Element Of " << i + 1 << " : " ;
        cin >> input;
        arr.push_back(input);
    }

    int ans = FindMajorityElement(arr);
    cout << "Majority Element In Array Is: " << ans << endl;
    
    return 0; 
}