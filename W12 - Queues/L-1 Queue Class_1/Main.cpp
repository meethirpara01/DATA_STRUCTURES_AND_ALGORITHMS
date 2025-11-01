#include <iostream>
#include <queue>
using namespace std;

class Dq
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Dq(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void pushFront(int val)
    {
        //OVER FLOW
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) // IMPORTENT
        {
            cout << "OverFlow" << endl;
            return;
        }
        else if (front == -1 && rear == -1) //EMPTY CASE
        {
            front++;
            rear++;
            arr[front] = val;
        }
        else if (front == 0 && rear != size - 1) // CIRCULAR CASE
        {
            front = size - 1;
            arr[front] = val;
        }
        else // NORMAL FLOW
        {
            front--;
            arr[front] = val;
        }
    }


    void pushBack(int val)
    {
        /* // overflow
         if (rear == size - 1)
         {
             cout << "OverFlow" << endl;
             return;
         }
         // empty case
         else if (front == -1 && rear == -1)
         {
             front++;
             rear++;
             arr[rear] = val;
         }
         // normal case
         else
         {
             rear++;
             arr[rear] = val;
         }
         */
        // The above code is garbage as humme Circular Nature maintain krna he padega
        // over flow
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) // imp condition
        {
            cout << "OverFlow" << endl;
            return;
        }
        // first Ele
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // circular Nature
        else if (rear == size - 1 & front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        // normal pushing
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void popFront()
    {
        if (rear == -1 && front == -1)
        {
            cout << "Queue underFlow" << endl;
            return;
        }
        else if (front == size - 1)
        {
            // single element
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    void popBack()
    {
        // undeflow
        if (front == -1 && rear == -1)
        {
            cout << "UnderFlow" << endl;
            return;
        }
        // single element
        else if (front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        // circular Nature
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        // normal Flow
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }
};

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