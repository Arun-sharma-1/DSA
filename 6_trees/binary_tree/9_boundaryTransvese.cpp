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
void leftTraverse(Node *p, vector<int> &ans)
{
    // we don't have to print the leaf nodes here
    Node *root = p;
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;
    ans.push_back(root->data);
    if (root->left)
        leftTraverse(root->left, ans);
    else
        leftTraverse(root->right, ans);
}
void leafTraverse(Node *p, vector<int> &ans)
{
    Node *root = p;
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        // leaf node
        ans.push_back(root->data);
        return;
    }
    leafTraverse(root->left, ans);
    leafTraverse(root->right, ans);
}
void rightTraverse(Node *root, vector<int> &ans)
{

    if ((root == NULL) )
        return;
    if(root->left == nullptr && root->right == nullptr) return;
    if (root->right)
        rightTraverse(root->right, ans);
    else
        rightTraverse(root->left, ans);

    ans.push_back(root->data);
}
vector<int> boundary(Node *root)
{
    vector<int> ans;
    // left
    ans.push_back(root->data);
    leftTraverse(root->left, ans);
    // //leaf node
    leafTraverse(root->left, ans);
    leafTraverse(root->right, ans);
    // //right --> reverse
    rightTraverse(root->right, ans);
    return ans;
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
    return 0;
}