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


// PROCCESS OF TO CONVERTING IN HEAP
// void storeInorerTraversal(Node* root, vector<int>& inorder)
// {
//     // BASE CASE
//     if (root == NULL)
//     {
//         return;
//     }

//     // LRN
//     // L
//     storeInorerTraversal(root->left, inorder);
    
//     // N
//     inorder.push_back(root->data);

//     // R
//     storeInorerTraversal(root->right, inorder);
// }

// void replaceUsingPostOrder(Node* root, vector<int>inorder, int &index)
// {
//     // BASE CASE
//     if (root == NULL)
//     {
//         return;
//     }

//     // LRN
//     // L
//     replaceUsingPostOrder(root->left, inorder, index);

//     // R
//     replaceUsingPostOrder(root->right, inorder, index);
    
//     // N
//     root->data = inorder[index];
//     index++;
// }

// Node* convertBStIntoMaxHeap(Node* root)
// {
//     // STEP 1 : CREATE INORDER
//     vector<int> inorder;
//     storeInorerTraversal(root, inorder);

//     // REPLACE THE NODE VALUE WITH THE SORTED INORDER VALUES, USING THE POSTORDER TRAVERSAL
//     int index = 0;
//     replaceUsingPostOrder(root, inorder, index);

//     return root;
// }

int main()
{
    Node *root = NULL;
    createBST(root);
    cout << "ROOT NODE: " << root->data << endl;

    cout << "LEVEL ORDER OF BST: " << endl;
    levelorderTraversalPrintInLevelWise(root);
    cout << endl;

    // cout << "CONVERTING IN TO HEAP: " << endl;
    // root = convertBStIntoMaxHeap(root);

    // cout << "LEVEL ORDER OF HEAP: " << endl;
    // levelorderTraversalPrintInLevelWise(root);
    // cout << endl;

    Info ans = checkMaxHeap(root);
    ans.isHeap ? cout << "CBT IS MAXHEAP" << endl : cout << "CBT IS NOT MAXHEAP" << endl;

    // 100 50 150 40 60 110 200 20 
    return 0;
}