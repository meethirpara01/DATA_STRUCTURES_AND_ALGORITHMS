// Debug the code.
#include <iostream>
using namespace std;

class MyCircularDeque
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    MyCircularDeque(int k)
    {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool insertFront(int value)
    {
        if (isFull())
        {
            return true;
        }
        if (front == -1 && rear == -1)
        {
            front = rear = -1;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
        {
            return true;
        }
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        arr[rear] = value;

        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if ((rear + 1) % size == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    cout << "";
    return 0;
}

// ANS
class MyCircularDeque
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    MyCircularDeque(int k)
    {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool insertFront(int value)
    {
        if (isFull())
        {
            // cout<<"queue is full";
            return false;
        }
        // for first element push
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = value;

        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
        {
            // cout<<"queue is full";
            return false;
        }
        // for first element push
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;

        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
        { // to check queue is empty
            return false;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }
        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        { // to check queue is empty
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if ((rear + 1) % size == front)
        {
            // cout<<"queue is full";
            return true;
        }
        else
        {
            return false;
        }
    }
};