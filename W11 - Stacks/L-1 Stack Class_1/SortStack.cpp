#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int element)
{
    // BASE CASE
    if (st.empty() || element > st.top())
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

void sortStack(stack<int> &st)
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
    sortStack(st);

    // BACKTRAKING
    insertSorted(st, temp);
}

int main()
{

    stack<int> st;
    st.push(10);
    st.push(7);
    st.push(12);
    st.push(5);
    st.push(11);
   
    sortStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}