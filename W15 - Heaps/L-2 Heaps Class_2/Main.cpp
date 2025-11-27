// I LEARN IN THIS LECTURE 
   // C++ STL FOR MIN AND MAX HEAP
   // FIND Kth SMALLEST ELEMENT AND FIND Kth GREATEST ELEMENT
   // CHECK CBT IS MAX HEAP OR NOT
   // CHECK TREE IS CBT OR NOT
   // CONVERT CBT + BST IN TO HEAP 


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

pair<bool, int> solve(Node *root)
{
        // base case
        if (root == NULL)
        {
                pair<bool, int> p = make_pair(true, INT_MIN);
                return p;
        }
        if (root->left == NULL && root->right == NULL)
        {
                // leaf node
                pair<bool, int> p = make_pair(true, root->data);
                return p;
        }

        pair<bool, int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);

        if (leftAns.first == true &&
            rightAns.first == true &&
            root->data > leftAns.second &&
            root->data > rightAns.second)
        {
                pair<bool, int> p = make_pair(true, root->data);
                return p;
        }

        else
        {
                pair<bool, int> p = make_pair(false, root->data);
                return p;
        }
}

int main()
{
        return 0;
}