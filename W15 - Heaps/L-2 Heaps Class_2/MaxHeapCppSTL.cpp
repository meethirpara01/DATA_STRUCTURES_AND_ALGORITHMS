#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // CREATE MAX-HEAP
    priority_queue<int> pq;
    
    // INSERTION
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout << "TOP ELEMENT OF HEAP: " << pq.top() << endl;

    pq.pop();
    cout << "TOP ELEMENT OF HEAP: " << pq.top() << endl;

    cout << "THE SIZE OF HEAP: " << pq.size() << endl;

    if (pq.empty())
        cout << "HEAP IS EMPTY" << endl;
    else
        cout << "HEAP IS NOT EMPTY" << endl;
    
    cout << endl;
    return 0;
}