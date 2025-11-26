#include <iostream>
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

class Info
{
    public:
        int maxVal;
        bool isHeap;

        Info(int a, bool b)
        {
            this->maxVal = a;
            this->isHeap = b;
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

    int count = 0;
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

Info checkMaxHeap(Node* root)
{
    // BASE CASE
    if(root == NULL)
    {
        Info temp(0, false);
        temp.maxVal = INT_MIN;
        temp.isHeap = true;
        return temp;
    }
    if (root->left == NULL && root->right == NULL)
    {
        Info temp(0, false);
        temp.maxVal = root->data;
        temp.isHeap = true;
        return temp;
    }
    
    // RECURSIVE CALL
    Info leftAns = checkMaxHeap(root->left);
    Info rightAns = checkMaxHeap(root->right);

    // BACKRAKCING
    if (root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap)
    {
        Info ans(0, false);
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    }
    else
    {
        Info ans(0, false);
        ans.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
        ans.isHeap = false;
        return ans;
    }
}

int main()
{
    Node *root = NULL;
    createBST(root);
    cout << "ROOT NODE: " << root->data << endl;

    Info ans = checkMaxHeap(root);
    ans.isHeap ? cout << "CBT IS MAXHEAP" << endl : cout << "CBT IS NOT MAXHEAP" << endl;

    // 50 30 40 20 60 55 70 80 25
    return 0;
}