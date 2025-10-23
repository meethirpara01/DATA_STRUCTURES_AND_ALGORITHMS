#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Destructor Called For :" << this->data << endl;
    }
};

void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int findLengthOfList(Node* head)
{
    Node* temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data)
{
    // LIST IS EMPTY
    if (head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else 
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } 
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    // LIST IS EMPTY
    if (head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else 
    {
        Node* newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } 
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    printList(head);

    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 50);
    printList(head);
    cout << endl;

    return 0;
}