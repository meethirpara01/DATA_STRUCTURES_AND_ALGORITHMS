#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }

    Node(int data)
    {
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

void removeDuplicate(Node* &head)
{
    if (head == NULL || head -> next == NULL)
    {
        return;
    }

    Node* temp = head;
    while (temp != NULL)
    {
        if (temp-> next != NULL && temp->data == temp->next->data)
        {
            Node* nextNode = temp -> next;
            temp -> next = nextNode -> next;
            nextNode -> next = NULL;
            delete nextNode;
        }
        else
            temp = temp -> next;    
    }
    return; 
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(3);
    Node *fifth = new Node(3);
    Node *sixth = new Node(4);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    Node* head = first;
    cout << "PRINTING LINKED LIST BEFORE REMOVE: " << endl << endl;
    printList(head);
    cout << endl;
    
    removeDuplicate(head);
    cout << "PRINTING LINKED LIST AFTER REMOVE: " << endl << endl;
    printList(head);
    cout << endl;
    return 0;
}