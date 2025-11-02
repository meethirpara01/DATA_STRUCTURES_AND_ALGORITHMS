#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void interleaveHalfQueue(queue<int> &second)
{
    queue<int> first;

    // PUSH FIRST HALF PART OD SECOND QUEUE IN FIRST QUEUE
    int size = second.size();
    for (int i = 0; i < size/2; i++)
    {
        int temp = second.front();
        second.pop();
        first.push(temp);
    }

    // MEARGE BOTH THE HALF
    // INTO THE ORIGINAL QUEUE - NAME AS SECOND
    for (int i = 0; i < size/2; i++)
    {
        int temp = first.front();
        first.pop();
        second.push(temp);

        temp = second.front();
        second.pop();
        second.push(temp);
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
    q.push(60);

    interleaveHalfQueue(q);
    cout << "PRINTING QUEUE AFTER INTERLEAVE HALF OF QUEUE: " << endl;
    while (!q.empty())
    {
        int qelement = q.front();
        cout << qelement << " ";
        q.pop();
    }
    return 0;
}