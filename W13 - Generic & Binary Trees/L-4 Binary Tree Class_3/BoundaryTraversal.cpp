#include <iostream>
#include <map>
#include <queue>
#include <utility>
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

void printLeftBoundary(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    // IF LEAF NODE COMES THAN RETURN THAT MEAN YOU PRINTED ALL NODE OF LEAFT BRANCH
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    // PRINT NODE
    cout << root->data << " ";

    // IF POSSIBLE TO GO IN LEFT THAN GO IF NOT ONLY IN THAT CASE GO RIGHT 
    if (root->left != NULL)
    {
        printLeftBoundary(root->left);
    }
    else 
    {
        printLeftBoundary(root->right);
    } 
}


void printLeafBoundary(Node* root)
{

    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}


void printRightBoundary(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    // IF LEAF NODE COMES THAN RETURN THAT MEAN YOU PRINTED ALL NODE OF LEAFT BRANCH
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    // IF POSSIBLE TO GO IN RIGHT THAN GO IF NOT ONLY IN THAT CASE GO LEFT 
    if (root->right != NULL)
    {
        printLeftBoundary(root->right);
    }
    else 
    {
        printLeftBoundary(root->left);
    } 

    // PRINT NODE
    cout << root->data << " ";
}

void boundaryTraversal(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    // PRINT ROOT NODE
    cout<< root->data << " ";

    // LEFT BRANCH
    printLeftBoundary(root->left);

    // NOW IF ROOT NODE IS ONLY NODE IN TREE THAT'S WHY PRINT LEAF NODE SPARETLY
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
    
    // RIGHT BRANCH
    printRightBoundary(root->right);

    // if (root->right != NULL)
    // {
    //     printRightBoundary(root->right);
    // }
    // else
    // {
    //     printRightBoundary(root->left);
    // }   
}

int main()
{
    Node* root = createTree();
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
    cout << "ROOT NODE: " << root->data << endl;

    cout << "BOUNDARY ELEMENT OF TREE: " << endl;
    boundaryTraversal(root);
    return 0;
}