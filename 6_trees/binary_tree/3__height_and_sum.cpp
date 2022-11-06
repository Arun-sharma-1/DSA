#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int ele)
    {
        left=right=nullptr;
        data=ele;
    }

};
int height_tree(Node *root)
{
    if(root==nullptr) return 0;
    int x = 0, y = 0;
    x=height_tree(root->left);
    y=height_tree(root->right);

    if (x > y)
        return x+1;
    else
        return y+1;
}
int sum_node(Node *root)
{
    int x = 0, y = 0;
    if (root != nullptr)
    {
        x = sum_node(root->left);
        y = sum_node(root->right);

        return x + y + root->data;
    }
    return 0;
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

    cout<<height_tree(root);
}