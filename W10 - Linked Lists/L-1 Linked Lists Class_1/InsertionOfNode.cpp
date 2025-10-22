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
};

int countLength(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        cout << temp->data << "->";
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

int main()
{
    // CREATION OF NODE
    // STATIC
    // Node a;

    // DYNEMICLY
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);
    // WITH THIS DATA INSERT IN NODE BUT EVERY NODE POINTES TO NULL
    // TO INSERT NEXT NODE NODE ADDRESS

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // NOW LINKED LIST IS CREATED!

    // Node *head = first;
    // Node *tail = fifth;
    // cout << "PRINTING ENTIRE LINKED LIST: " << endl;
    // int ans = countLength(head);
    // cout << endl;
    // cout << "LENGTH OF LINKED LIST: " << ans << endl;
    // cout << endl;
    // cout << endl;

    // insertAtHead(head, tail, 500);
    // cout << "PRINTING ENTIRE LINKED LIST AFTER INSERT NODE AT HEAD: " << endl;
    // int ans1 = countLength(head);
    // cout << endl;
    // cout << "LENGTH OF LINKED LIST AFTER INSERT NODE AT HEAD: " << ans1 << endl;
    // cout << endl;
    // cout << endl;

    // insertAtTail(head, tail, 500);
    // cout << "PRINTING ENTIRE LINKED LIST AFTER INSERT NODE AT HEAD: " << endl;
    // int ans2 = countLength(head);
    // cout << endl;
    // cout << "LENGTH OF LINKED LIST AFTER INSERT NODE AT HEAD: " << ans2 << endl;
    // cout << endl;
    // cout << endl;

    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 77);
    insertAtTail(head, tail, 90);
    

    countLength(head);
    cout << endl;

    insertAtPosition(head, tail, 10, 1);
    cout << endl;
    insertAtPosition(head, tail, 55, 3);
    cout << endl;
    insertAtPosition(head, tail, 75, 5);
    cout << endl;
    insertAtPosition(head, tail, 100, 10);
    cout << endl;

    countLength(head);
    cout << endl;
    return 0;
}