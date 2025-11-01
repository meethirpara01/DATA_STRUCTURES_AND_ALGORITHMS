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
        else if (front == -1 && rear == -1) // FIRST ELEMENT
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
        // OVER FLOW
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) // IMPORTENT
        {
            cout << "OverFlow" << endl;
            return;
        }
        // FIRST ELEMENT
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        // CIRCULAR CASE
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        // NORMAL CASE
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
        // SINGLE ELEMENT
        else if (front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        // CIRCULAR CASE
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        // NORMAL CASE
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void popBack()
    {
        // UNDER FLOW 
        if (front == -1 && rear == -1)
        {
            cout << "UnderFlow" << endl;
            return;
        }
        // SINGLE ELEMENT
        else if (front == rear)
        {
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        // CIRCULAR CASE
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        // NORMAL CASE
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }

    void print()
    {
        cout << "Printing Queue: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Dq()
    {
        cout << "Destructor Called" << endl;
        delete[] arr;
    }
};

int main()
{
    Dq q(6);
    q.print();

    // q.pushBack(60);
    // q.print();
    // cout << endl;

    // q.pushFront(10);
    // q.print();
    // cout << endl;

    // q.pushBack(50);
    // q.print();
    // cout << endl;

    // q.pushFront(20);
    // q.print();
    // cout << endl;

    // q.pushBack(40);
    // q.print();
    // cout << endl;

    // q.pushFront(30);
    // q.print();
    // cout << endl;
    
    // q.pushFront(100);
    // q.print();
    // cout << endl;

    q.pushFront(100);
    q.print();
    cout << endl;

    q.pushBack(200);
    q.print();
    cout << endl;

    q.pushBack(200);
    q.print();
    cout << endl;

    q.pushBack(200);
    q.print();
    cout << endl;

    q.pushBack(200);
    q.print();
    cout << endl;

    q.pushBack(200);
    q.print();
    cout << endl;

    q.popFront();
    q.print();

    q.pushBack(200);
    q.print();
    cout << endl;
    return 0;
}