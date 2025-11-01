#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // dequeue
    //(Doubly Ended Queue)
    // front se pop push and rear se push pop
    // #include<dequeu>->include
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(20);

    cout << "Size of DQ: " << dq.size() << endl;
    cout << "Front Ele: " << dq.front() << endl;
    cout << "Back Ele(Rear Ele): " << dq.back() << endl;

    dq.pop_front();
    cout << "Size of DQ: " << dq.size() << endl;
    cout << "Front Ele: " << dq.front() << endl;
    cout << "Back Ele(Rear Ele): " << dq.back() << endl;
    // process scheduling types of queue  -> OS
    // Implement Doubly Ended Queue From Scratch
    // Circular Dq->HomeWWork
    return 0;
}