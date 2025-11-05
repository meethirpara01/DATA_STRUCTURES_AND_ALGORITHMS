// Debug the code. Next Greater Element.
#include <iostream>
using namespace std;

class MyCircularQueue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    MyCircularQueue(int n)
    {
        arr = new int[n];
        rear = -1;
        qfront = -1;
        size = n;
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            qfront = rear = 0;
        }
        else
        {
            rear = (rear + 1);
        }
        arr[rear] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        if (qfront == rear)
        {
            qfront = -1;
        }
        else
        {
            qfront = (qfront + 1);
        }
        return true;
    }

    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[qfront];
    }

    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        return qfront;
    }

    bool isFull()
    {
        return (qfront == 0 && rear == size - 1) || (qfront == rear + 1);
    }
};

int main()
{

    return 0;
}

// ANS
// class MyCircularQueue {
//     int* arr;
//     int qfront;
//     int rear;
//     int size;
// public:
//     MyCircularQueue(int n) {
//         arr = new int[n];
//         rear = -1;
//         qfront = -1;
//         size = n;
//     }

//     bool enQueue(int value) {
//         if (isFull()) {
//             return false;
//         }
//         if (isEmpty()) {
//             qfront = rear = 0;
//         } else {
//             rear = (rear + 1) % size;
//         }
//         arr[rear] = value;
//         return true;
//     }

//     bool deQueue() {
//         if (isEmpty()) {
//             return false;
//         }
//         if (qfront == rear) {
//             qfront = rear = -1;
//         } else {
//             qfront = (qfront + 1) % size;
//         }
//         return true;
//     }

//     int Front() {
//         if (isEmpty()) {
//             return -1;
//         }
//         return arr[qfront];
//     }

//     int Rear() {
//         if (isEmpty()) {
//             return -1;
//         }
//         return arr[rear];
//     }

//     bool isEmpty() {
//         return qfront == -1;
//     }

//     bool isFull() {
//         return (qfront == 0 && rear == size - 1) || (qfront == rear + 1);
//     }
// };