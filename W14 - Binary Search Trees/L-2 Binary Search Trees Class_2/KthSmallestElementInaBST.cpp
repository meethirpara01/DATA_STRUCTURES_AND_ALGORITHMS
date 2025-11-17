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

int kthSmallest(Node* root, int &k)
{
    // BASE CASE
    if (root == NULL)
    {
        return -1;
    }

    // INORDER TRAVERSAL - LNR
    // L
    int leftAns = kthSmallest(root->left, k);
    if (leftAns != -1)
    {
        return leftAns;
    }

    // N
    k--;
    if (k == 0)
    {
        return root->data;
    }

    // R
    int rightAns = kthSmallest(root->right, k);
    return rightAns; // IF OUR ANSWER NOT COME THOUGHOUT LEFTCALL AND N - CURR NODE THAN WE HAVE TO RETURN SOMETHING THAT'S WHY IN LAST RETURN rightAns 
}

int main()
{
    Node *root = NULL;
    createBST(root);
    cout << "ROOT NODE: " << root->data << endl;

    cout << "LEVEL ORDER OF BST: " << endl;
    levelorderTraversalPrintInLevelWise(root);
    cout << endl;

    int k;
    cout << "ENTER KTH VLAUE: ";
    cin >> k;

    int ans = kthSmallest(root, k);
    cout << "KTH SMALLEST ELEMENT IS: " << ans << endl;

    // 50 30 40 20 60 55 70 80 25
    return 0;
}