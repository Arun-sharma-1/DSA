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
void inorder(Node *root, vector<int> &v)
{
    if (root != nullptr)
    {
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    else
        v.push_back(100000);
}
void preorder(Node *root, vector<int> &v)
{
    if (root != nullptr)
    {
        v.push_back(root->data);
        preorder(root->left, v);
        preorder(root->right, v);
    }
    else
    {
        v.push_back(100000);
    }
}
bool isSameTree(Node *p, Node *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;
    return (p->data == q->data && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(11);

    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(10);
    root->right->right = new Node(5);

    root->right->right->left = new Node(6);
    root->right->right->left->left = new Node(8);
    root->right->right->left->right = new Node(9);

    root->right->right->right = new Node(7);

    vector<int> a, b, c, d;
    inorder(p, a);
    inorder(q, b);
    preorder(p, c);
    preorder(q, d);
    if (a == b && c == d)
        return true;
    return false;
}