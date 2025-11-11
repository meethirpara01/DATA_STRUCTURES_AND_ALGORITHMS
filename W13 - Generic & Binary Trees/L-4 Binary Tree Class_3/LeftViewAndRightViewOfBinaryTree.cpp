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

Node *createTree()
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
    Node *root = new Node(data);

    // STEP:- 2 CREATE LEFT SUBTREE - RECURSIVE CALL
    cout << "Left of Node: " << root->data << endl;
    root->left = createTree();

    // STEP:- 3 CREATE RIGHT SUBTREE - RECURSIVE CALL
    cout << "Right Of Node: " << root->data << endl;
    root->right = createTree();

    return root;
}

void preorderTraversal(Node *root)
{
    // NRL
    // BASE CASE
    if (root == NULL)
    {
        return;
    }

    // N
    cout << root->data << " ";

    // L
    preorderTraversal(root->left);

    // R
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root)
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
    cout << root->data << " ";

    // R
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root)
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
    cout << root->data << " ";
}

void levelorderTraversal(Node *root)
{
    // INITIAL STAPE
    queue<Node *> q;
    q.push(root);

    // TRAVERSAL
    while (!q.empty())
    {
        // FETCH QUEUE
        Node *front = q.front();
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

void printLeftView(Node *root, int level, vector<int> &leftview)
{
    // BASE CASE
    if (root == NULL)
    {
        return;
    }

    // PROCCESSING
    if (level == leftview.size())
    {
        // THAT MEAN WE GOT THE LEFT VIEW NODE
        leftview.push_back(root->data);
    }

    // RECURSIVE CALL
    printLeftView(root->left, level + 1, leftview);
    printLeftView(root->right, level + 1, leftview);
}

void printRightView(Node *root, int level, vector<int> &rightview)
{
    // BASE CASE
    if (root == NULL)
    {
        return;
    }

    // PROCCESSING
    if (level == rightview.size())
    {
        // THAT MEAN WE GOT THE RIGHT VIEW NODE
        rightview.push_back(root->data);
    }

    // RECURSIVE CALL - CHANGE THE ORDER OF CALLING RE
    printRightView(root->right, level + 1, rightview);
    printRightView(root->left, level + 1, rightview);
}

int main()
{
    Node *root = createTree();
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
    cout << "ROOT NODE: " << root->data << endl;

    vector<int> leftView;
    printLeftView(root, 0, leftView);

    cout << "Printing Left View: " << endl;
    for (int i = 0; i < leftView.size(); i++)
    {
        cout << leftView[i] << " ";
    }
    cout << endl;

    vector<int> rightView;
    printRightView(root, 0, rightView);

    cout << "Printing rightView: " << endl;
    for (int i = 0; i < rightView.size(); i++)
    {
        cout << rightView[i] << " ";
    }
    cout << endl;
    return 0;
}