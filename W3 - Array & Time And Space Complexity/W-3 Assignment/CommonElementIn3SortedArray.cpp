#include <iostream>
#include <set>
#include <vector>
using namespace std;
// T.C = O(arr + brr + crr)
// S.C = O(arr)
vector<int> UserDefineHash(int arr[], int size, int brr[], int size1, int crr[], int size2)
{
    vector<int> ans;
    set<int> st;
    int i = 0, j = 0, k = 0;

    while (i < size && j < size1 && k < size2)
    {
        if (arr[i] == brr[j] && brr[j] == crr[k])
        {
            st.insert(arr[i]);
            i++;
            j++;
            k++;
        }
        else if (arr[i] < brr[j])
            i++;
        else if (brr[j] < crr[k])
            j++;
        else
            k++;
    }

    for (auto x : st)
        ans.push_back(x);
    return ans;
}

int main()
{
    int size, size1, size2;

    cout << "Enter Size Of Array First: ";
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Array Element " << i << ": ";
        cin >> arr[i];
    }

    cout << "Enter Size Of Array Second: ";
    cin >> size1;
    vector<int> brr(size1);
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter Array Element " << i << ": ";
        cin >> brr[i];
    }

    cout << "Enter Size Of Array Third: ";
    cin >> size2;
    vector<int> crr(size2);
    for (int i = 0; i < size2; i++)
    {
        cout << "Enter Array Element " << i << ": ";
        cin >> crr[i];
    }

    vector<int> ans = UserDefineHash(arr.data(), size, brr.data(), size1, crr.data(), size2);

    cout << "Common Elements are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
