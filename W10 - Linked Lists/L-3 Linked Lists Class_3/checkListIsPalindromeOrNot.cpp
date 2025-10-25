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

Node *FindMiddleNoteUsingSlowFast(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL) // CATCH
        {
            fast = fast->next;
            slow = slow -> next;
        }
    }

    return slow;
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

bool isPalindrome(Node* head)
{
    //BREAK IN TO TWO PARTS
    Node* midnote = FindMiddleNoteUsingSlowFast(head);
    Node* head2 = midnote -> next;
    midnote -> next = NULL;

    // REVERSE SECOEND HALF
    Node* prev = NULL;
    Node* curr = head2;
    head2 = reverseUsingRecursion(prev, curr);

    // COMPARE BOTH LISTS
    Node* temp = head;
    Node* temp2 = head2;
    while (temp != NULL && temp2 != NULL)
    {
        if (temp->data != temp2->data)
        {
            return false;
        }
        else
        {
            temp = temp -> next;
            temp2 = temp2 -> next;
        }
    }

    return true;
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

    Node *head = first;
    cout << "PRINTING LINKED LIST: " << endl<< endl;
    printList(head);
    cout << endl;

    bool ans = isPalindrome(head);
    ans ? cout << "LIST IS PALINDROME!" << endl : cout << "LIST IS NOT PALINDROME!" << endl;
    cout << endl;
    return 0;
}