#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

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
};

void printLL(Node* head)
{
    Node * temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    // CREATION OF NODE 
    // STATIC
    // Node a;
    
    // DYNEMICLY
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    // WITH THIS DATA INSERT IN NODE BUT EVERY NODE POINTES TO NULL  
    // TO INSERT NEXT NODE NODE ADDRESS  

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // NOW LINKED LIST IS CREATED!

    Node* head = first;
    cout << "PRINTING ENTIRE LINKED LIST: " << endl;
    printLL(head);

    return 0;
}