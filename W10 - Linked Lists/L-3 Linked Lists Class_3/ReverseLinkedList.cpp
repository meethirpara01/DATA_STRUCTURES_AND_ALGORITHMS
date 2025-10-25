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

Node* reverseUsingRecursion(Node* prev, Node* curr)
{
    // BASE CASE
    if (curr == NULL)
    {
        return prev; 
    }

    // PROCCESING - SOLVE ONE CASE
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;


    // RECURSIVE CALL
    Node* recursiveAns = reverseUsingRecursion(prev, curr); 
    return recursiveAns;
}

Node* reverseList(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;

    // while (curr != NULL)
    // {
    //     Node* next = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = next;
    // }

    // head = prev;
    // return head;

    return reverseUsingRecursion(prev, curr); 
}

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* head = first;
    cout << "PRINTING LINKED LIST BEFORE REVERSE: " << endl << endl;
    printList(head);
    cout << endl;
    
    
    head = reverseList(head);
    cout << "PRINTING LINKED LIST AFTER REVERSE: " << endl << endl;
    printList(head);
    cout << endl;
    return 0;
}