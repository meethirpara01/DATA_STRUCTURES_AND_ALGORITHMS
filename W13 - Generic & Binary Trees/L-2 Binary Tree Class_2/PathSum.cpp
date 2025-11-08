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

bool solve(Node* root, int targetSum, int sum)
{
    // BASE CASE
    if (root == NULL)
    {
        return false;
    }

    // ROCCESSING
    sum += root->data;

    if (root->left == NULL && root->right == NULL)
    {
        // I AM CURRENTLY STANDING ON A LEAF NODE
        // VERIFY
        if (sum == targetSum)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    // RECURSIVE CALL
    bool leftAns = solve(root->left, targetSum, sum);
    bool rightAns = solve(root->right, targetSum, sum);

    return leftAns || rightAns;
}

bool sumPath(Node* root, int target)
{
    int sum = 0;
    bool ans = solve(root, target, sum);
    return ans;
}

int main()
{
    Node* root = createTree();
    cout << "ROOT NODE: " << root->data << endl;
    
    int target;
    cout << "Enter Tergerd Sum: ";
    cin >> target;

    bool ans = sumPath(root, target);
    ans ? cout << "TARGETED SUM IS EQUALE TO ONE PATH OF TREE" << endl : cout << "TARGETED SUM IS NOT EQUALE TO ANY PATH OF TREE" << endl;
    return 0;
}