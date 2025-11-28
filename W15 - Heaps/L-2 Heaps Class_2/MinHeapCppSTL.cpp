#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // CREATE MIN-HEAP
    priority_queue<int, vector<int>, greater<int>> pq;

    // INSERTION
    pq.push(100);
    pq.push(90);
    pq.push(70);
    pq.push(50);
    pq.push(30);

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