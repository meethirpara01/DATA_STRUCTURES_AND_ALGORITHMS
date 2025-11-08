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

int heightOfTree(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->left);
    int height = max(leftHeight, rightHeight);

    return height;
}

bool balanceTreeOrNot(Node* root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    int diff = abs(leftHeight - rightHeight);

    bool currNodeAns = (diff >= 1);

    bool leftAns = balanceTreeOrNot(root->left);
    bool rightAns = balanceTreeOrNot(root->right);

    if (currNodeAns && leftAns && rightAns)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int main()
{
    Node* root = createTree();
    cout << "ROOT NODE: " << root->data << endl;
    
    bool ans = balanceTreeOrNot(root);
    (ans) ? cout <<"TREE IS BALANCED" << endl : cout << "TREE IS NOT BALANCED" << endl;
    cout << endl;
    return 0;
}