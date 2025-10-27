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

int main()
{

  stack<int> st;
  st.push(10);
  st.push(7);
  st.push(12);
  st.push(5);
  st.push(11);

  int element = 400;
  insertAtBottom(st, element);

  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}