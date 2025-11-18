#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelorderTraversalPrintInLevelWise(Node *root)
{
    // INITIAL STAPE
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // TRAVERSAL
    while (q.size() > 1) // (!q.empty())
    {
        // FETCH QUEUE
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            q.push(NULL); // IF(!q.empty()) ONLY PUSH IN THIS CASE
        }
        else
        {
            cout << front->data << " ";

            // PUSH LEFT
            if (front->left != NULL)
            {
                q.push(front->left);
            }

            // PUSH RIGHT
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

Node* createBSTUsingInorder(int in[], int start, int end)
{
    // BASE CASE
    if (start > end)
    {
        return NULL;
    }

    // PROCCESSING
    int mid = start + (end - start) / 2;
    int element = in[mid];
    Node* root = new Node(element);

    // RECURSIVE CALL
    root->left = createBSTUsingInorder(in, start, mid - 1);
    root->right = createBSTUsingInorder(in, mid + 1, end);

    return root;
}

void printLinkedList(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->right;
    }
    cout << endl;
}

Node* convertDLLtoBST(Node* &head, int n)
{
    // BASE CASE 
    if (head == NULL || n <= 0)
    {
        return NULL;
    }

    // LNR
    // L
    Node* leftSubTree = convertDLLtoBST(head, n/2);

    // N
    Node* root = head;
    root->left = leftSubTree;
    // UPADET HEAD
    head = head->right;

    // R
    Node* rightSubTree = convertDLLtoBST(head, n - n/2 - 1);
    root->right = rightSubTree;
    return root;    
}


int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;

    Node* head = first;
    // 10<->20<->30

    
    Node* root = convertDLLtoBST(head, 3);

    cout << "LEVEL ORDER OF BST: " << endl;
    levelorderTraversalPrintInLevelWise(root);
    cout << endl;
    
    return 0;
}