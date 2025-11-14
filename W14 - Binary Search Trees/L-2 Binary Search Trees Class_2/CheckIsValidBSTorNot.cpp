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

bool solve(Node* root, long long int lowerBound, long long int upperBound)
{
    // BASE CASE
    if (root == NULL)
    {
        return true;
    }

    // PROCCESSING
    bool con1 = (root->data > lowerBound);
    bool con2 = (root->data < upperBound);

    // RECURSION CALL
    bool leftAns = solve(root->left, lowerBound, root->data);
    bool rightAns = solve(root->right, root->data, upperBound);
    
    if (con1 && con2 && leftAns && rightAns)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool isvalidBST(Node* root)
{
    long long int lowerBound = -2147483657; // INT_MAX - 10
    long long int upperBound = 2147483657; // INT_MAX + 10

    bool ans = solve(root, lowerBound, upperBound);
    return ans;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    cout << "ROOT NODE: " << root->data << endl;

    cout << "LEVEL ORDER OF BST: " << endl;
    levelorderTraversalPrintInLevelWise(root);
    cout << endl;

    bool ans = isvalidBST(root);
    ans ? cout << "YOUR GIVEN TREE IS VALID BST" << endl : cout << "YOUR GIVEN TREE IS VALID BST" << endl;

    // 50 30 40 20 60 55 70 80 25
    return 0;
}