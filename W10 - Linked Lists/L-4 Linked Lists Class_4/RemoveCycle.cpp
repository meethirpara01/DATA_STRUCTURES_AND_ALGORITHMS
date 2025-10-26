#include <iostream>
#include <map>
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

void removeCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        
        // CJECK FOR LOOP
        if (fast == slow)
            break;
    }
    // LOOP NOT PRESENT
    slow = head;

    // SLOW AND FAST MOVE 1 STEP
    while (fast != slow)
    {
        slow = slow -> next;
        fast = fast -> next;
    }

    Node* startingPoint =  slow;

    Node* temp = slow;
    while (temp -> next != startingPoint)
    {
        temp = temp -> next;
    }

    temp -> next = NULL;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;

    Node *head = first;

    removeCycle(head);
    cout << "LOOP REMOVED: " << endl;
    cout << "PRINTG LIST: " << endl;
    printList(head);
    cout << endl;
    return 0;
}