#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &element)
{
    // BASE CASE
    if (st.empty())
    {
        st.push(element);
        return;
    }

    // PROCCESSING
    int temp = st.top();
    st.pop();

    // RECURSION CALL
    insertAtBottom(st, element);

    // BACKTRAKING
    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    // BASE CASE
    if (st.empty())
    {
        return;
    }

    // PROCCESSING
    int temp = st.top();
    st.pop();

    // RECURSION CALL
    reverseStack(st);

    // BACKTRAKING
    insertAtBottom(st, temp);
}

int main()
{

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    // without reverse:
    // 30 20 10

    reverseStack(st);
    // with reverse:
    // 10 20 30

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}