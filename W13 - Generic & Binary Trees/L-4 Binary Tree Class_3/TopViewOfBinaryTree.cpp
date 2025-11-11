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

void printTopView(Node* root)
{

    map<int, int> hdToNodemap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // IF THEIR IS NO ENTRY FOR HD IN MAP, THAN CREATE A NEW ENTRY
        if (hdToNodemap.find(hd) == hdToNodemap.end())
        {
            hdToNodemap[hd] = frontNode->data;
        }

        //CHECK FOR CHILD 
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        } 
    }

    cout << "PRTING TOP VIEW: " << endl;
    for(auto i: hdToNodemap)
    {
        cout << i.second << " ";
    }
}

int main()
{
    Node* root = createTree();
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    cout << "ROOT NODE: " << root->data << endl;

    printTopView(root);
    return 0;
}