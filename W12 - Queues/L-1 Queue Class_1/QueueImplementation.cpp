#include <iostream>
#include <queue>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        if (rear == size - 1)
        {
            cout << "Queue OverFlow" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }


    void pop()
    {
        if (rear == -1 && front == -1)
        {
            cout << "Queue underFlow" << endl;
            return;
        }
        else if (front == rear) // SINGLE ELEMENT
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }


    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }


    int getSize()
    {
        // IMPORTENT
        if (front == -1 && rear == -1)
            return 0;
        else
            return (rear - front + 1);
    }


    int getFront()
    {
        if (front == -1)
        {
            cout << "Noe lement in the Queue" << endl;
            return -1;
        }
        else
            return arr[front];
    }


    int getRear()
    {
        if (rear == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[rear];
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


    ~Queue()
    {
        cout << "Destructor Called" << endl;
        delete[] arr;
    }
};

int main()
{
    Queue q(5);
    q.print();
    cout << endl;

    q.push(10);
    q.print();
    cout << endl;

    q.push(20);
    q.print();
    cout << endl;

    q.push(30);
    q.print();
    cout << endl;
    
    q.push(40);
    q.print();
    cout << endl;

    q.push(50);
    q.print();
    cout << "SIZE OF QUEUE: "<< q.getSize() << endl;
    cout << endl;
    
    q.pop();
    q.print();
    cout << "SIZE OF QUEUE: "<< q.getSize() << endl;
    cout << endl;
    
    
    cout << "QUEUE IS EMPTY OR NOT: "<< q.isEmpty() << endl;
    cout << endl;

    cout << "Front Element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << endl;

    q.push(100);
    q.print();
    cout << endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    cout << "SIZE OF QUEUE: "<< q.getSize() << endl;
    cout << endl;
    return 0;
}