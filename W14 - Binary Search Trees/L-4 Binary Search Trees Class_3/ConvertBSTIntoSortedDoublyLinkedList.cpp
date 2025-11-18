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

void convertBSTtoDLL(Node* root, Node* &head)
{
    if (root == NULL)
    {
        return;
    }

    // RNL
    // R
    convertBSTtoDLL(root->right, head);


    // N
    // ATTACHING NEXT POINTER OF CURRENT NODE TO HEAD OF LL
    root->right = head;
    // ATTACHING PREV POINTER OF HEAD OF LL TO CURRENT NODE
    if (head != NULL)
    {
        head -> left = root;
    }
    // UPDATE HEAD
    head = root;
    
    
    // L
    convertBSTtoDLL(root->left, head);
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


int main()
{
    int size;
    cout << "ENTER SIZE OF INORDER: ";
    cin >> size;

    int in[size];
    for (int i = 0; i < size; i++)
    {
        cout << "ENTER " << i + 1 << " ELEMENT OF INORDER: ";
        cin >> in[i];
    }
    
    Node* root = createBSTUsingInorder(in, 0, size - 1);

    cout << "LEVEL ORDER OF BST: " << endl;
    levelorderTraversalPrintInLevelWise(root);
    cout << endl;

    Node* head = NULL;
    convertBSTtoDLL(root, head);
    printLinkedList(head);
    
    return 0;
}