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

Node* checkCycleUsingSlowFast(Node* head)
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

    return slow;
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
    fifth->next = fourth;

    Node *head = first;

    Node* temp = checkCycleUsingSlowFast(head);
    cout << "STARTING NODE OF CYCLE IS: " << endl;
    cout << temp -> data << endl;
    cout << endl;
    return 0;
}