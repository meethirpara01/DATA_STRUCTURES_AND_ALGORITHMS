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

void AddOne(Node* &head)
{
    // REVERSE
    Node* prev = NULL;
    Node* curr = head;
    head = reverseUsingRecursion(prev, curr); 

    // ADD 1
    int carry = 1;
    Node* temp = head;
    while (temp->next != NULL)
    {
        int totalSum = temp -> data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp -> data = digit;
        temp = temp -> next;

        if (carry == 0)
        {
            break;
        }
    }

    if (carry != 0)
    {
        int totalSum = temp -> data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp -> data = digit;

        if (carry != 0)
        {
            Node* newNode = new Node(carry);
            temp -> next = newNode; 
        }
    }

    // REVERSE
    prev = NULL;
    curr = head;
    head = reverseUsingRecursion(prev, curr);
}

int main()
{
    Node* first = new Node(9);
    Node* second = new Node(9);
    Node* third = new Node(9);

    first->next = second;
    second->next = third;

    Node* head = first;
    cout << "PRINTING LINKED LIST BEFORE ADDICTION: " << endl << endl;
    printList(head);
    cout << endl;
    
    AddOne(head);
    cout << "PRINTING LINKED LIST AFTER ADDICTION: " << endl << endl;
    printList(head);
    cout << endl;
    return 0;
}