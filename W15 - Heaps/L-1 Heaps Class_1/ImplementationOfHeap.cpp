#include <iostream>
using namespace std;

class Heap
{
    public:
        int *arr;
        int capacity;
        int size;

        Heap(int capacity)
        {
            this->arr = new int[capacity];
            this->capacity = capacity;
            // CURRENTE NUMBER OF ELEMENT IN HEAP
            this->size = 0;
        }

        void insert(int val)
        {
            if (size == capacity)
            {
                cout << "HEAP OVERFLOW" << endl;;
                return;
            }
            
            // SIZE WILL BE INCRESE
            size++;
            int index = size;
            arr[index] = val;

            // TAKE THE VALUE TO ITS CORRECT POSITION
            while (index > 1)
            {
                int parentIndex = index/2;
                if (arr[index] > arr[parentIndex])
                {
                    swap(arr[index], arr[parentIndex]);
                    index = parentIndex;
                }
                else 
                {
                    break;
                }
            }
        }

        int deleteFromHeap()
        {
            int answer = arr[1];

            // REPLACEMENT 
            arr[1] = arr[size];
            // DELETE LAST ELEMENT FROM THEIR ORIGINAL POSITION
            size--;

            int index = 1;
            while (index < size)
            {
                int leftIndex = 2 * index;
                int rightIndex = 2 * index + 1;

                // FIND OUT WHICH ELEMENT IS BIGGRE IN THIS THREE ELEMENT
                int largestIndex = index;
                // CHECK LEFT CHILD
                if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
                {
                    arr[largestIndex] = leftIndex;
                }
                if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
                {
                    arr[largestIndex] = rightIndex;
                }

                // NO CHANGE
                if (index == largestIndex)
                {
                    break;
                }
                else
                {
                    swap(arr[index], arr[largestIndex]);
                    index = largestIndex;
                }
            }
            return answer;
        }

        void printHeap()
        {
            cout << "PRINTING THE CONTENT OF HEAP: " << endl;
            for (int i = 1; i <= size; i++)
            {
                cout << arr[i] << " ";
            } 
        }
};


void heapfiy(int *arr, int n, int index)
{
    // NO NEED OF BASE CASE
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;

    // FIND OUT WHICH ELEMENT IS BIGGRE IN THIS THREE ELEMENT
    int largestIndex = index;
    // CHECK LEFT CHILD
    if (leftIndex <= n && arr[largestIndex] < arr[leftIndex])
    {
        arr[largestIndex] = leftIndex;
    }
    if (rightIndex <= n && arr[largestIndex] < arr[rightIndex])
    {
        arr[largestIndex] = rightIndex;
    }

    // NO CHANGE
    if (index != largestIndex)
    {
        swap(arr[index], arr[largestIndex]);
        // RECURSIVE CALL
        index = largestIndex;
        heapfiy(arr, n, index);
    }
}

int main()
{
    Heap h(20);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    h.printHeap();
    cout << endl;

    int ans = h.deleteFromHeap();
    cout << "Answer: " << ans << endl;
    h.printHeap();
    cout << endl;

    // 5 10 15 6 25 50
    return 0;
}