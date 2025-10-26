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

Node* reverseInKGroupUsingRE(Node* head, int k)
{
    // BASE CASE
    if (head == NULL || head -> next == NULL)
    {
        return head; 
    }

    // PROCCESING - SOLVE ONE CASE
    Node* prev = NULL;
    Node* curr = head;
    int position = 0;
    Node* nextNode = NULL;
    while (position < k)
    {
        position++;
        nextNode = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    // RECURSIVE CALL
    if(nextNode != NULL)
    {
        head -> next = reverseInKGroupUsingRE(nextNode, k);
    }
    
    return prev;
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

    Node* head = first;
    cout << "PRINTING LINKED LIST BEFORE REVERSE: " << endl << endl;
    printList(head);
    cout << endl;
    
    cout << "PRINTING LINKED LIST AFTER REVERSE: " << endl << endl;
    head = reverseInKGroupUsingRE(head, 2);
    printList(head);
    cout << endl;
    return 0;
}