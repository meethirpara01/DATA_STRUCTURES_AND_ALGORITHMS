#include<iostream>
using namespace std; 
void printArray(int integer, vector<int> &ans)
{
    // BASE CASE
    if (integer == 0)
        return;

    // PROCCESING
    int digit = integer % 10;
    integer /= 10; 
    
    // RECURSIVE CALL
    printArray(integer, ans);

    // PROCCESING
    ans.push_back(digit); // WE CAN ALSO DO cout << digit << " ";
    return;
}

int main() 
{ 
    int integer;
    cout << "Enter Size Of Array : "; 
    cin >> integer;

    vector<int> ans;

    printArray(integer, ans);
    cout << endl;

    for(auto num : ans)
        cout << num << " ";
    cout << endl;

    return 0; 
}