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

void solve(Node* root, int targetSum, vector<vector<int>>& ans, vector<int> temp, int sum)
{
    // BASE CASE
    if (root == NULL)
    {
        return;
    }

    // ROCCESSING
    sum += root->data;
    temp.push_back(root-> data);

    // EXTRA CHECK
    if (root->left == NULL && root->right == NULL)
    {
        // I AM CURRENTLY STANDING ON A LEAF NODE
        // VERIFY
        if (sum == targetSum)
        {
            // STORE PATH IN ANS VECTOR
            ans.push_back(temp);
        }
        else 
        {
            return;
        }
    }

    // RECURSIVE CALL
    solve(root->left, targetSum, ans, temp, sum);
    solve(root->right, targetSum, ans, temp, sum);
}

vector<vector<int>> sumPath2(Node* root, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    solve(root, target, ans, temp, sum);
    return ans;
}

int main()
{
    Node* root = createTree();
    cout << "ROOT NODE: " << root->data << endl;
    
    int target;
    cout << "Enter Tergerd Sum: ";
    cin >> target;

    vector<vector<int>> ans = sumPath2(root, target);
    for(auto path: ans)
    {
        for (auto elem: path)
        {
            cout << elem << " ";
        }
        cout << "endl";
    }
    return 0;
}