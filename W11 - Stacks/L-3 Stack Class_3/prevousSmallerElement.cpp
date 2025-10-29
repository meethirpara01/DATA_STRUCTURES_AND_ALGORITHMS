#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void prevSmallerElement(int *arr, int size, vector<int> &ans)
{
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];

        // FIND ANSWER FOR CURR
        while (st.top() >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        // PUSH CURR IN TO STACK BECAUSE THAT COULD ALSO BE SOMEONE ELSE'S ANSWER
        st.push(curr);
    }
}

int main()
{
    int size;
    cout << "ENTER SIZE OF ARRAY: " << endl;
    cin >> size;

    int arr[size];
    vector<int> ans(size);
    for (int i = 0; i < size; i++)
    {
        cout << "ENTER ELEMENT " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << endl;

    prevSmallerElement(arr, size, ans);
    cout << "YOUR SMALLER ELEMENTS ARE: " << endl; 
    for (auto elem: ans)
    {
        cout << elem << " ";
    }
    return 0;
}