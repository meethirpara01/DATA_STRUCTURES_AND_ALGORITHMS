#include <iostream>
#include <queue>
using namespace std;

class CircularQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        // OVERFLOW
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) // CATCH
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
        // CIRCULAR NATURE
        else if (rear == size - 1 & front != 0)
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


    void pop()
    {
        // UNDERFLOW
        if (front == -1 && rear == -1)
        {
            cout << "UnderFlow" << endl;
            return;
        }
        // SINGLE ELEMNT
        else if (front == rear)
        {
            // important
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // CIRCULAR NATURE
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

    void print()
    {
        cout << "Printing Queue: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~CircularQueue()
    {
        cout << "Destructor Called" << endl;
        delete[] arr;
    }
};

int main()
{

    CircularQueue q(5);
    q.print();
    cout << endl;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();
    cout << endl;

    q.push(69);
    q.print();

    q.pop();
    q.pop();
    q.pop();
    q.print();
    cout << endl;

    q.push(100);
    q.push(110);
    q.push(120);
    q.print();
    cout << endl;

    q.push(130);
    q.print();
    cout << endl;

    return 0;
}