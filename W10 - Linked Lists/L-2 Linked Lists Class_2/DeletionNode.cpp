#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        cout << "Default Constructor Called!" << endl;
        this->next = NULL;
    }

    Node(int data)
    {
        cout << "Param Constructor Called!" << endl;
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Destructor Called For :" << this->data << endl;
    }
};

void printList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int countLength(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        // cout << temp->data << "->";
        temp = temp->next;
    }

    return count;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // CREATE NEW NODE
        Node *newNode = new Node(data);
        // UPDATE HEAD AND TAIL
        head = newNode;
        tail = newNode;
        // NOW IT'S BECOME SINGLE ELEMENT LL
    }
    else
    {
        // CREATE NEW NODE
        Node *newNode = new Node(data);
        // ATTACH NEW NODE TO HEAD NODE
        newNode->next = head;
        // UPDATE HEAD
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // CREATE NEW NODE
        Node *newNode = new Node(data);
        // UPDATE HEAD AND TAIL
        head = newNode;
        tail = newNode;
        // NOW IT'S BECOME SINGLE ELEMENT LL
    }
    else
    {
        // CREATE NEW NODE
        Node *newNode = new Node(data);
        // ATTACH NEW NODE TO TAIL NODE
        tail->next = newNode;
        // UPDATE TAIL
        tail = newNode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    int length = countLength(head);

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
        // INSERT AT MIDDEL OF THE LINKED LIST
        // STEP:1 CREATE A NEW NODE
        Node *newNode = new Node(data);

        // STEP:2 TRAVERSE PREV / CURR TO POSITION
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }

        // STEP:3 ATTACH PREV TO NEW NODE
        prev->next = newNode;

        // STEP:4 ATTACH NEWNODE TO CURR
        newNode->next = curr;
    }
}


void DeletionNode(Node *&head, Node *&tail, int position)
{
    int length = countLength(head);

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
        delete temp;
    }

    else if (position >= length)
    {
        // DELETE LAST NODE
        // FIND PREV
        Node* prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }

        // POINT NULL TO PREV
        prev->next = NULL;

        // DELETE TAIL NODE 
        delete tail;

        // UPDATE TAIL
        tail = prev;
    }
    else
    {
        // DELETE FROM MIDDLE
        Node* prev = NULL;
        Node* curr = head;
        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }

        // POINT PREV TO CURR NEXT
        prev->next = curr->next;

        // POINT CURR TO NULL
        curr->next = NULL;

        // DELETE CURR
        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    printList(head);
    cout << endl;

    DeletionNode(head, tail, 1);
    printList(head);
    cout << endl;

    DeletionNode(head, tail, 4);
    printList(head);
    cout << endl;

    DeletionNode(head, tail, 2);
    printList(head);
    cout << endl;
    
    DeletionNode(head, tail, 5);
    printList(head);
    cout << endl;
    
    DeletionNode(head, tail, 0);
    printList(head);
    cout << endl;


    return 0;
}