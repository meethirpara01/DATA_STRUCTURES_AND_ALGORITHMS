#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int element)
{
    // BASE CASE
    if (st.empty() || element > st.top()) // CATCH
    {
        st.push(element);
        return;
    }

    // PROCCESSING
    int temp = st.top();
    st.pop();

    // RECURSION CALL
    insertSorted(st, element);

    // BACKTRAKING
    st.push(temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    
    insertSorted(st,35);
    
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}