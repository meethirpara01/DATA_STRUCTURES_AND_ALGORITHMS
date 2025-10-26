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

bool hashCycle(Node* head)
{
    map<Node*, bool> table;

    Node* temp = head;
    while (temp != NULL)
    {
        if (table[temp] == false)
        {
            table[temp] = true;
        }
        
        else
        {
            // CYCLE PRESENT
            return true;
        }
        temp = temp -> next; 
    }
    // LOOP NOT PRESENT
    return false;
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(2);
    Node *fifth = new Node(1);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = fourth;

    Node *head = first;

    bool ans = hashCycle(head);
    ans ? cout << "CYCLE PRESENT!" << endl : cout << "CYCLE NOT PRESENT!" << endl;
    cout << endl;
    return 0;
}