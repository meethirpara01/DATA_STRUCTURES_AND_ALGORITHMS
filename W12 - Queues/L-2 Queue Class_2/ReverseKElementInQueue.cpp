#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseQueueWithKElement(queue<int> &q, int k)
{
    stack<int> s;
    int n = q.size();

    if (k > n || k ==0)
        return;
    
    // PUSH IN STACK AND POP FROM QUEUE
    for(int i = 0; i < k; i++)
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

    // PUSH N-K ELEMENT IN LAST
    for (int i = 0; i < n - k; i++)
    {
        int frontElement = q.front();
        q.pop();
        q.push(frontElement);  
    }  
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    int k = 0;
    cout << "Enter K Element: ";
    cin >> k;

    reverseQueueWithKElement(q, k);
    cout << "PRINTING QUEUE AFTER REVERSE WITH K ELEMENT: " << endl;
    while (!q.empty())
    {
        int qelement = q.front();
        cout << qelement << " ";
        q.pop();
    }
    return 0;
}