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

Node* lowestCommonAncestor(Node* root, Node*  p, Node* q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == p->data)
    {
        return p;
    }
    if (root->data == q->data)
    {
        return q;
    }

    Node* leftAns = lowestCommonAncestor(root->left, p, q);
    Node* rightAns = lowestCommonAncestor(root->right, p, q);

    if (leftAns == NULL && rightAns == NULL)
        return NULL;
    if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    else 
        return root;
}

int main()
{
    Node* root = createTree();
    cout << "ROOT NODE: " << root->data << endl;
    
    Node* p = root->left->left;
    Node* q = root->right->right;

    Node* LCA = lowestCommonAncestor(root, p, q);
    cout << "LOWEST COMMON ANCESTOR IS: " << LCA << endl;
    return 0;
}