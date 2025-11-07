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

int heightOfTreeMaxDepthWithRE(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = heightOfTreeMaxDepthWithRE(root->left);
    int rightHeight = heightOfTreeMaxDepthWithRE(root->left);
    int height = max(leftHeight, rightHeight);

    return height;
}

int levelorderTraversal(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    
    // INITIAL STAPE
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int count = 1;

    // TRAVERSAL
    while (q.size() > 1) // (!q.empty())
    {
        // FETCH QUEUE
        Node* front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl; 
            q.push(NULL); // IF(!q.empty()) ONLY PUSH IN THIS CASE
            count++;
        }
        else
        {
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

    return count;
}

int main()
{
    Node* root = createTree();
    cout << "ROOT NODE: " << root->data << endl;
  
    int ans1 = heightOfTreeMaxDepthWithRE(root);
    cout << "HEIGHT OF TREE IS: " << ans1 << endl;
    cout << endl;
    
    cout <<"LEVEL IS EQUAL TO HEIGHT OF TREE: " << endl;
    int ans2 = levelorderTraversal(root);
    cout << "HEIGHT OF TREE IS: " << ans2 << endl;
    cout << endl;
    return 0;
}