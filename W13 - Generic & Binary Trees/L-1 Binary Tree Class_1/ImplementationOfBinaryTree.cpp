#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* createTree()
{
    cout << "Enter the value for Node: " << endl;
    int data;
    cin >> data;

    // BASE CASE
    if (data == -1)
    {
        return NULL;
    }

    // STEP:- 1 CREATE NEW NODE - PROCCESSING
    Node* root = new Node(data);

    // STEP:- 2 CREATE LEFT SUBTREE - RECURSIVE CALL
    cout << "Left of Node: " << root->data << endl;
    root->left = createTree();

    // STEP:- 3 CREATE RIGHT SUBTREE - RECURSIVE CALL
    cout << "Right Of Node: " << root->data << endl;
    root->right = createTree();

    return root;
}

void preorderTraversal(Node* root)
{
    // NRL
    // BASE CASE
    if (root == NULL)
    {
        return;
    }

    // N
    cout << root-> data << " ";

    // L
    preorderTraversal(root->left);
    
    // R
    preorderTraversal(root->right);
}

void inorderTraversal(Node* root)
{
    // NRL
    // BASE CASE
    if (root == NULL)
    {
        return;
    }

    // L
    inorderTraversal(root->left);

    // N
    cout << root-> data << " ";
    
    // R
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root)
{
    // NRL
    // BASE CASE
    if (root == NULL)
    {
        return;
    }

    // L
    postorderTraversal(root->left);

    // R
    postorderTraversal(root->right);

    // N
    cout << root-> data << " ";
}

void levelorderTraversal(Node* root)
{
    // INITIAL STAPE
    queue<Node*> q;
    q.push(root);

    // TRAVERSAL
    while (!q.empty())
    {
        // FETCH QUEUE
        Node* front = q.front();
        q.pop();

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

void levelorderTraversalPrintInLevelWise(Node* root)
{
    // INITIAL STAPE
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    // TRAVERSAL
    while (q.size() > 1) // (!q.empty())
    {
        // FETCH QUEUE
        Node* front = q.front();
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

int main()
{
    Node* root = createTree();
    cout << "ROOT NODE: " << root->data << endl;

    cout <<"PRE ORDER OF TREE: " << endl;
    preorderTraversal(root);
    cout << endl;
    
    cout <<"IN ORDER OF TREE: " << endl;
    inorderTraversal(root);
    cout << endl;
    
    cout <<"POST ORDER OF TREE: " << endl;
    postorderTraversal(root);
    cout << endl;
    
    cout <<"LEVEL ORDER OF TREE: " << endl;
    levelorderTraversal(root);
    cout << endl;
    
    cout <<"LEVEL ORDER OF TREE: " << endl;
    levelorderTraversalPrintInLevelWise(root);
    cout << endl;
    return 0;
}