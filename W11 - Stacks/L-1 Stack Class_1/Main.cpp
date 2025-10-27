// I LEARN IN THIS LECTURE IS
  // WHAT IS STACK ?
  // C++ STACK STL
  // STACK IMPLEMENTATION
  // WHEN TO STACK - REVERSE AN STRING USING STACK
  // FIND MIDDLE ELEMENT OF STACK
  // INSER ELEMENT AT BOTTOM AT STACK
  // REVERSE AN STACK
  // INSERT ELEMENT IN SORTED STATCK
  // SORT AN STACK

#include <iostream>
#include<stack>
using namespace std;

int main() {

  //creation
  stack<int> st;

  //insertion
  st.push(10);
  st.push(20);
  st.push(30);

  //size check
  cout << "Size of stack is: " << st.size() << endl;

  //remove 
  st.pop(); 

  //check empty
  if(st.empty()) {
    cout << "Stack is empty" << endl;
  }
  else {
    cout << "stack is non empty" << endl;
  }


  //top element
  cout << st.top() << endl;


  return 0;
}