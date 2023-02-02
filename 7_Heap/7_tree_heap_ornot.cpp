#include <bits/stdc++.h>
using namespaces std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int countNodes(Node *root)
{
    if (root == nullptr)
        return 0;
    int l = countNodes(root->left);
    int r = countNodes(root->right);
    return l + r + 1;
}
bool CBT(Node *root, int index, int total)
{
    // leaf
    if (root == nullptr)
        return true;
    // index > total(node) means gap is present
    if (index >= total)
        return false;
    // both left and right present
    else
    {
        bool left = CBT(root->left, 2 * index + 1, total);
        bool right = CBT(root->right, 2 * index + 2, total);
        return (left && right);
    }
}
bool maxHeap(Node *root)
{
    // leaf node null
    if (root->left == nullptr && root->right == nullptr)
        return true; // leaf nodes already heap
    // cbt -> right nul ho skta h
    // cbt->left null nhi ho ksta h

    if (root->right == nullptr)
    {
        return root->data > root->left->data;
    }
    else
    {
        bool left = maxHeap(root->left);
        bool right = maxHeap(root->right);
        return (left && right && root->data > root->left->data && root->data > root->right->data);
    }
}
bool isHeap(struct Node *tree)
{
    // code here

    int totalNodes = countNodes(tree);
    if (CBT(tree, 0, totalNodes) && maxHeap(tree))
        return true;
    else
        return false;
}
int main()
{
    
}