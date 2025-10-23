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

void insertAtPosition(Node* &head, Node* &tail, int data, int position)
{
    int length = findLengthOfList(head);

    // LIST IS EMPTY
    if (head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else 
    {
        if (position <= 1)
        {
            insertAtHead(head, tail, data);
        }
        else if (position > length)
        {
            insertAtTail(head, tail, data);
        }
        else
        {
            // INSERT AT MIDDLE
            // STEP1: CREAT AN NODE
            Node* newNode = new Node(data);

            // STEP2: SET PREV AND CURR POINTER
            Node* prevNode = NULL;
            Node* currNode = head;
            while (position != 1)
            {
                prevNode = currNode;
                currNode = currNode->next;
                position--;
            }

            // STEP3: UPDATE POINTERS
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        } 
    } 
}

void DeletionNode(Node *&head, Node *&tail, int position)
{
    int length = findLengthOfList(head);

    // EMPTY LIST
    if (head == NULL)
    {
        cout << "CAN NOT DELETE, BECAUSE LL IS EMPTY" << endl;
        return;
    }

    // FOR SINGLE ELEMENT
    else if (head == tail)
    {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }

    //DELETE FROM HEAD
    else if (position <= 1)
    {
        // DELETE FIRST NODE
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }

    else if (position >= length)
    {
        // DELETE LAST NODE
        Node* prevNode = tail->prev;

        // POINT NULL TO PREVNODE AND TAIL
        prevNode->next = NULL;
        tail->prev = NULL;

        // DELETE TAIL NODE 
        delete tail;

        // UPDATE TAIL
        tail = prevNode;
    }
    else
    {
        // DELETE FROM MIDDLE
        Node* prevNode = NULL;
        Node* currNode = head;
        while (position != 1)
        {
            prevNode = currNode;
            currNode = currNode->next;
            position--;
        }
        Node* nextNode = currNode->next;

        // CONNECT PREVNODE AND NEXTNODE AND DELETE CURRNODE
        prevNode->next = nextNode;
        currNode->next = NULL;
        currNode->prev = NULL;
        nextNode->prev = prevNode;

        // DELETE CURR
        delete currNode;
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
    insertAtPosition(head, tail, 25, 3);
    printList(head);
    cout << endl;

    DeletionNode(head, tail, 3);
    DeletionNode(head, tail, 5);
    DeletionNode(head, tail, 0);
    printList(head);
    cout << endl;

    return 0;
}