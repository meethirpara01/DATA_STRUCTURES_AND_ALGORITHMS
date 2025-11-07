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

int DiameterOfTree(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int option1 = DiameterOfTree(root->left);
    int option2 = DiameterOfTree(root->right);
    int option3 = heightOfTree(root->left) + heightOfTree(root->right);
    int diameter = max(option1, max(option2, option3));

    return diameter;
}

int main()
{
    Node* root = createTree();
    cout << "ROOT NODE: " << root->data << endl;
    
    int ans = DiameterOfTree(root);
    cout <<"DIAMETER OF TREE IS: " << ans << endl;
    cout << endl;
    return 0;
}