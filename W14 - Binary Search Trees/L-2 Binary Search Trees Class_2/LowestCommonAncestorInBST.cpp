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

Node* lowestCommonAncestorInBST(Node* root, Node*  p, Node* q)
{
    if (root == NULL)
    {
        return NULL;
    }

    // CASE 1: P AND Q BOTH ARE COMES IN LEFT SUBTREE OF NODE
    if (p->data < root->data && q->data < root->data)
    {
        Node* leftAns =  lowestCommonAncestorInBST(root->left, p, q);
        return leftAns;
    }
    // CASE 2: P AND Q BOTH ARE COMES IN RIGHT SUBTREE OF NODE
    if (p->data > root->data && q->data > root->data)
    {
        Node* rightAns =  lowestCommonAncestorInBST(root->right, p, q);
        return rightAns;
    }
    // CASE 3: P IS IN LEFT SUBTREE OF ROOT NODE AND Q IS IN RIGHT SUBTREE OF ROOT NODE
    // if (p->data < root->data && q->data > root->data)
    // {
    //     return root;
    // }
    // CASE 4: P IS IN RIGHT SUBTREE OF ROOT NODE AND Q IS IN LEFT SUBTREE OF ROOT NODE
    // if (p->data > root->data && q->data < root->data)
    // {
    //     return root;
    // }

    // NO NEED TO WRITE CASE 3 AND CASE 4 WITHOUT THIS TWO CASE YOUR CODE ALSO CAN ABLE TO RUN  
    return root; // BECAUSE OF THIS
}

int main()
{
    Node *root = NULL;
    createBST(root);
    cout << "ROOT NODE: " << root->data << endl;

    cout << "LEVEL ORDER OF BST: " << endl;
    levelorderTraversalPrintInLevelWise(root);
    cout << endl;
    
    Node* p = root->left->left;
    Node* q = root->right->right;

    Node* LCA = lowestCommonAncestorInBST(root, p, q);
    cout << "LOWEST COMMON ANCESTOR IS: " << LCA->data << endl;

    // 50 30 40 20 60 55 70 80 25
    return 0;
}