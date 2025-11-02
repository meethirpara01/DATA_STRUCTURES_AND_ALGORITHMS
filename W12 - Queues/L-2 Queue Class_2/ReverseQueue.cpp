#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;
    // PUSH IN STACK AND POP FROM QUEUE
    while (!q.empty())
    {
        int frontElement = q.front();
        q.pop();
        s.push(frontElement);
    }
    
    // PUSH IN QUEUE AND POP FROM STACK
    while (!s.empty())
    {
        int sElement = s.top();
        s.pop();
        q.push(sElement);
    }
}

void reverseQueueUsingRE(queue<int> &q)
{
    // BASE CASE
    if (q.empty())
    {
        return;
    }

    // PROCCESSING
    int temp = q.front();
    q.pop();

    // RECURSION CALL
    reverseQueueUsingRE(q);

    // BACKTRACKING
    q.push(temp);
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverseQueueUsingRE(q);
    cout << "PRINTING QUEUE AFTER REVERSE: " << endl;
    while (!q.empty())
    {
        int qelement = q.front();
        cout << qelement << " ";
        q.pop();
    }
    return 0;
}