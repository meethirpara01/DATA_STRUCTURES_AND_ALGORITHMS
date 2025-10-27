#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans)
{
  // BASE CASE
  if (pos == 1)
  {
    ans =  st.top();
    // IF YOU WANT TO DELETE MIDDLE ELEMENT
    // cout << "Deleting " << st.top() << endl;
    // st.pop();
    return;
  }

  // PROCCESSING
  pos--;
  int temp = st.top();
  st.pop();

  // RECURSION CALL
  solve(st, pos, ans);

  // BACKTRAKING
  st.push(temp);
}

int getMiddleElement(stack<int> &st)
{
  int size = st.size();
  if (st.empty())
  {
    cout << "Stack is empty, no middle element" << endl;
    return -1;
  }
  else
  {
    // STACK IS NOT EMPTY
    // ODD
    int pos = 0;
    if (size & 1)
    {
      pos = size / 2 + 1;
    }
    else
    {
      // EVEN
      pos = size / 2;
    }
    int ans = -1;
    solve(st, pos, ans);
    return ans;
  }
}

int main()
{
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(50);
  st.push(60);

  cout << "before size" << st.size() << endl;
  int mid = getMiddleElement(st);
  cout << "Middle element: " << mid << endl;

  cout << "after size" << st.size() << endl;
  return 0;
}