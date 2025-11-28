#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next = NULL;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class compare
{
    public:
        bool operator()(Node* a, Node* b)
        {
            return a->data > b->data;
        }
};

Node* mergeKSortedLinkedList(vector<Node*> &lists)
{
    priority_queue<Node*, vector<Node*>, compare> pq;

    // STEP 1 :- PROCESS FIRST K LISTS
    for (int i = 0; i < lists.size(); i++)
    {
        Node* listHead = lists[i];
        if (listHead != NULL) // MAKE SURE YOU CHECK THIS EDGE CASE
        {
            pq.push(listHead);
        }
    }

    // FOR NEW LL
    Node* head = NULL;
    Node* tail = NULL;

    while (!pq.empty())
    {
        Node* topNode = pq.top();
        pq.pop();
        
        // YE FRONT NODE JO NIKALI H,
        // YE HAMARI FIRST NODE HO SAKTI HAI
        if (head == NULL)
        {
            // INSERT THE FIRST NODE
            head = topNode;
            tail = topNode;

            // INSERT NEXT NODE IN HEAP
            if (tail->next != NULL) // ALSO WE CAN WRITE (topNode->next != NULL)
            {
                pq.push(tail->next);
            }
        }
        else 
        {
            tail->next = topNode;
            tail = topNode;

            // INSERT NEXT NODE IN HEAP
            if (tail->next != NULL) // ALSO WE CAN WRITE (topNode->next != NULL)
            {
                pq.push(tail->next);
            }
        } 
    } 
    
    return head;
}

int main()
{
    cout << "";
    return 0;
}