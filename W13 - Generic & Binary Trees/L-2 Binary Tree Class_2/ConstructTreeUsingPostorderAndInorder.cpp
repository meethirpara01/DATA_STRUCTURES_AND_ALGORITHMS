#include <iostream>
#include <queue>
#include <map>
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

void levelOrderTraversal(Node *root)
{
    // INITIAL STAPE
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

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

int searchInorder(int inorder[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void createMapping(int inorder[], int size, map<int, int> &valueToIndexMap)
{
    for (int i = 0; i < size; i++)
    {
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

Node *constructTreeFromPostAndInorderTraversal(map<int, int> &valueToIndexMap, int postOrder[], int inOrder[], int &postIndex, int inOrderStart, int inOrderEnd, int size)
{
    // BASE CASE
    if (postIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // SOLVE ONE CASE
    // PROCCESSING
    int element = postOrder[postIndex];
    postIndex--;
    Node *root = new Node(element);

    // SEARCH ELEMENT IN INORDER AND FIND THEIR POSITION IN INORDER
    // int position = searchInorder(inOrder, size, element);
    int position = valueToIndexMap[element];


    // RECURSIVE CALL
    root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, position + 1, inOrderEnd, size);

    root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, inOrderStart, position - 1, size);

    return root;
}

int main()
{
    // int size;
    // cout << "Enter Size Of Order: ";
    // cin >> size;

    // int inorder[size];
    // cout << "Enter Element For INORDER" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter inorder's " << i + 1 << "element :";
    //     cin >> inorder[i];
    // }
    
    // int postorder[size];
    // cout << "Enter Element For POSTORDER" << endl;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter postorder's " << i + 1 << "element :";
    //     cin >> postorder[i];
    // }
    
    int inorder[] = {8, 14, 6, 2, 10, 4};
    int postOrder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postOrderIndex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    map<int, int> valueToIndexMap;
    createMapping(inorder, size, valueToIndexMap);

    Node *root = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inorder, postOrderIndex, inorderStart, inorderEnd, size);
    levelOrderTraversal(root);
    return 0;
}