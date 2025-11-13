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

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        // CREATE FIRST NODE
        root = new Node(data);
        return root;
    }

    // ITS NOT THE FIRST NODE
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else // (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void createBST(Node *&root)
{
    int data;
    cout << "Enter Data: ";
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter Data: ";
        cin >> data;
    }
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

Node* minValue(Node *root)
{
    if (root == NULL)
    {
        cout << "NO MIN VALUE" << endl;
        return NULL;
    }

    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

Node* maxValue(Node *root)
{
    if (root == NULL)
    {
        cout << "NO MAX VALUE" << endl;
        return NULL;
    }

    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp;
}

bool searchInBST(Node *root, int target)
{
    // BASE CASE
    if (root == NULL)
    {
        return false;
    }

    // PROCCESSING
    if (root->data == target)
    {
        return true;
    }

    bool leftAns = false;
    bool rightAns = false;

    // RECURSION CALL
    if (target > root->data)
    {
        rightAns = searchInBST(root->right, target);
    }
    else // (target < root->data)
    {
        leftAns = searchInBST(root->left, target);
    }
    
    return leftAns || rightAns;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    cout << "ROOT NODE: " << root->data << endl;

    cout << "LEVEL ORDER OF BST: " << endl;
    levelorderTraversalPrintInLevelWise(root);
    cout << endl;

    cout << "PRE ORDER OF BST: " << endl;
    preorderTraversal(root);
    cout << endl;

    cout << "IN ORDER OF BST: " << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "POST ORDER OF BST: " << endl;
    postorderTraversal(root);
    cout << endl;

    cout << "MINMUM VALUE IN BST: " << endl;
    Node *ans1 = minValue(root);
    if (ans1 == NULL)
    {
        cout << "THERE IS NO NODE IN TREE" << endl;
    }
    cout << ans1->data << endl;

    cout << "MAXMIM VALUE IN BST: " << endl;
    Node *ans2 = maxValue(root);
    if (ans2 == NULL)
    {
        cout << "THERE IS NO NODE IN TREE" << endl;
    }
    cout << ans2->data << endl;

    int target;
    cout << "Enter Target To Find: ";
    cin >> target;

    bool flag = searchInBST(root, target);
    flag ? cout << "TARGET FOUND" << endl : cout << "TARGET NOT FOUND" << endl;

    // 50 30 40 20 60 55 70 80 25
    return 0;
}