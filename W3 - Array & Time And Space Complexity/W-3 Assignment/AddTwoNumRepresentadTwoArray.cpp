#include<iostream>
using namespace std; 

string AddNumbersOfArray(int arr[], int size, int brr[], int size1)
{
    string ans;
    int i = size - 1;
    int j = size1 - 1;
    int carry = 0;

    while (i >= 0 && j >= 0)
    {
        int x = arr[i] + brr[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--;
        j--;
    }

    while (i >= 0 )
    {
        int x = arr[i] + 0 + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        i--;
    }

    while (j >= 0)
    {
        int x = 0 + brr[j] + carry;
        int digit = x % 10;
        ans.push_back(digit + '0');
        carry = x / 10;
        j--;
    }

    while (ans[ans.size() - 1] == 0)
        ans.pop_back();

    reverse(ans.begin(), ans.end());

    return ans;
    
    

}
int main() 
{ 
    int size, size1;

    cout << "Enter Size Of Array First: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array Element " << i << ": ";
        cin >> arr[i];
    }

    cout << "Enter Size Of Array Second: ";
    cin >> size1;
    int brr[size1];
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter Array Element " << i << ": ";
        cin >> brr[i];
    }

    string ans = AddNumbersOfArray(arr, size, brr, size1);
    cout<< "Total Sum Is :" << ans << endl;
    return 0; 
}