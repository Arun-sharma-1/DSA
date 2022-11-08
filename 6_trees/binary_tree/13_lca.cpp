#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int ele)
    {
        left = right = nullptr;
        data = ele;
    }
};
Node *lca(Node *root, int n1, int n2)
{
    // Your code here
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftans = lca(root->left, n1, n2);
    Node *rightans = lca(root->right, n1, n2);

    if (leftans && rightans)
        return root;
    if (leftans == nullptr && rightans)
        return rightans;
    if (leftans && rightans == nullptr)
        return leftans;
    else
        return nullptr;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);

    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    root->right->left->left = new Node(50);
    root->right->left->right = new Node(60);
    root->right->left->left->left = new Node(70);

    root->right->left->right->right = new Node(80);
    root->right->left->right->right->left = new Node(90);

    cout << diameter(root);
}