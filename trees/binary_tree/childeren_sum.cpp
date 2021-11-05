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
bool children_sum(Node *root)
{
    if(root==nullptr) return true;

    if(root->left==nullptr && root->right == nullptr) return true;
    
    int sum=0;
    if(root->left) sum+=root->left->data;
    if(root->right) sum+=root->right->data;
    
    return (root->data == sum && children_sum(root->left) && children_sum(root->right));
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

    children_sum(root);
}