#include <iostream>
#include <queue>
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

Node *minValue(Node *root)
{
    if (root == NULL)
    {
        cout << "NO MIN VALUE" << endl;
        return NULL;
    }

    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

Node* maxValue(Node *root)
{
    if (root == NULL)
    {
        cout << "NO MAX VALUE" << endl;
        return NULL;
    }

    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp;
}

Node *deleteNodeFromBST(Node *root, int target)
{
    // FIND THE TARGET
    // AND DELETE THE TARGET
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        // NOW DELETE TARGET
        // 4 CASES

        // FIRST CASE --> LEAF NODE
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // SECOEND CASE --> LEFT NOT NULL AND RIGHT NULL
        else if (root->left != NULL && root->right == NULL)
        {
            Node *childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        // THIRD CASE --> LEFT NULL AND RIGHT NOT NULL
        else if (root->left == NULL && root->right != NULL)
        {
            Node *childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        // FOURTH CASE --> LEFT NOT NULL AND RIGHT NOT NULL
        else
        {
            // CHHOSE CASE A -> FIND MAXIMUM VALUE OF LEFT SUB TREE
            Node* maxi = maxValue(root->left);
            // REPLACEMENT
            root->data = maxi->data;

            // DELETE ACTUAL MAXI NODE
            root->left = deleteNodeFromBST(root->left, maxi->data);
            return root;
        }
    }
    else if (root->data > target)
    {
        // FIND IN LEFT
        root->left = deleteNodeFromBST(root->left, target);
    }
    else // (root->data < target)
    {
        // FIND IN RIGHT
        root->right = deleteNodeFromBST(root->right, target);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    cout << "ROOT NODE: " << root->data << endl;

    cout << "LEVEL ORDER OF BST: " << endl;
    levelorderTraversalPrintInLevelWise(root);
    cout << endl;

    cout << "MINMUM VALUE IN BST: " << endl;
    Node *ans1 = minValue(root);
    if (ans1 == NULL)
    {
        cout << "THERE IS NO NODE IN TREE" << endl;
    }
    cout << ans1->data << endl;

    cout << "MAXMIM VALUE IN BST: " << endl;
    Node *ans2 = maxValue(root);
    if (ans2 == NULL)
    {
        cout << "THERE IS NO NODE IN TREE" << endl;
    }
    cout << ans2->data << endl;

    int target;
    cout << "ENTER TARGETD NODE TO DELETE: ";
    cin >> target;

    while (target != -1)
    {
        root = deleteNodeFromBST(root, target);
        cout << endl;
        cout << "LEVEL ORDER OF BST: " << endl;
        levelorderTraversalPrintInLevelWise(root);
        cout << endl;
        cout << "ENTER TARGETD NODE TO DELETE: ";
        cin >> target;
    }
    

    // 50 30 40 20 60 55 70 80 25
    return 0;
}