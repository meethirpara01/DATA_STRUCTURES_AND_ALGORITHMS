#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(5);
    cout << "Size of Queue: " << q.size() << endl;
    cout << "Element in Queue: " << q.front() << endl;

    q.pop();
    cout << "Size of Queue: " << q.size() << endl;
    cout << "Queue is empty: " << q.empty() << endl;

    q.push(10);
    cout << "Element in Queue: " << q.front() << endl;

    q.push(15);
    cout << "Last Element in the Queue: " << q.back() << endl;
    
    q.push(20);
    cout << "Last Element in the Queue: " << q.back() << endl;

    return 0;
}