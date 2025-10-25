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

int FindLength(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *FindMiddleNoteUsingBruteForce(Node *head)
{
    int len = FindLength(head);
    int position = len / 2 + 1;

    Node *temp = head;
    while (position != 1)
    {
        position--;
        temp = temp->next;
    }

    return temp;
}

Node *FindMiddleNoteUsingSlowFast(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL) // FOR n/2 POSITION IN EVEN CASE ONDITION IS: (fast->next != NULL)
    {
        fast = fast->next;
        if (fast != NULL) // CATCH // MOVE ONLY ONE STEP AND CHECK NEXT STEP IS NOT NULL ? IF YES THAT RETURN SLOW
        // FOR n/2 POSITION IN EVEN CASE ONDITION IS: (fast->next != NULL)
        {
            fast = fast->next;
            // FAST MOVED 2 STEP NOW SLOW IS FREE TO MOVE 1 STEP
            slow = slow -> next;
        }
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
    Node *sixth = new Node(60);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    Node *head = first;
    cout << "PRINTING LINKED LIST: " << endl
         << endl;
    printList(head);
    cout << endl;

    Node *node = FindMiddleNoteUsingSlowFast(head);
    cout << "Middle Element Of List Is: " << node->data << endl;
    cout << endl;
    return 0;
}