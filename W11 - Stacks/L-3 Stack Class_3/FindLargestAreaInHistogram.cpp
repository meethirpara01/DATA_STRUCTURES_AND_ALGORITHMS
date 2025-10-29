#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr)
{
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int curr = arr[i];

        // FIND ANSWER FOR CURR
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr)
{
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < arr.size(); i++)
    {
        int curr = arr[i];

        // FIND ANSWER FOR CURR
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &height)
{
    vector<int> next = nextSmallerElement(height);
    for (int i = 0; i < next.size(); i++)
    {
        if (next[i] == -1) // CATCH
        {
            next[i] = height.size();
        }
    }
    vector<int> prev = prevSmallerElement(height);

    vector<int> area(next.size());
    for (int i = 0; i < next.size(); i++)
    {
        int width = next[i] - prev[i] - 1;
        int length = height[i];
        int currArea = width * length;
        area[i] = currArea;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < area.size(); i++)
    {
        maxi = max(maxi, area[i]);
    }

    return maxi;
}

int main()
{
    int size;
    cout << "ENTER SIZE OF ARRAY: " << endl;
    cin >> size;

    vector<int> height(size);
    for (int i = 0; i < size; i++)
    {
        cout << "ENTER ELEMENT " << i + 1 << ": ";
        int input;
        cin >> input;
        height.push_back(input);
    }
    cout << endl;

    int ans = largestRectangleArea(height);
    cout << "LARGEST AREA OF HISTOGRAM IS: " << ans << endl; 
    return 0;
}