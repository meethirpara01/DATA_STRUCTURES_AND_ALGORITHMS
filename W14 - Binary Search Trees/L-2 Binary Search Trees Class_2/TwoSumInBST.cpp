#include <iostream>
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

void storeInorder(Node *root, vector<int> &inorder)
{
    // BASE CASE
    if (root == NULL)
    {
        return;
    }

    // LNR
    // L
    storeInorder(root->left, inorder);
    // N
    inorder.push_back(root->data);
    // R
    storeInorder(root->right, inorder);
}

bool findTarget(Node *root, int k)
{
    vector<int> inorder;
    storeInorder(root, inorder);

    // FIND TARGET USING 2 POINTER APPROACH
    int start = 0;
    int end = inorder.size() - 1;

    while (start < end)
    {
        int sum = inorder[start] + inorder[end];
        if (sum == k)
        {
            return true;
        }
        else if (sum > k)
        {
            end--;
        }
        else if (sum < k)
        {
            start++;
        }
    }
    return false;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    cout << "ROOT NODE: " << root->data << endl;

    cout << "LEVEL ORDER OF BST: " << endl;
    levelorderTraversalPrintInLevelWise(root);
    cout << endl;

    int target;
    cout << "ENTER KTH TARGET: ";
    cin >> target;

    bool ans = findTarget(root, target);
    ans ? cout << "TARGET FOUND" << endl : cout << "TARGET NOT FOUND" << endl;

    // 50 30 40 20 60 55 70 80 25
    return 0;
}