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
void leftTransversal(Node *p, vector<int> &ans)
{
    // we don't have to print the leaf nodes here
    Node *root = p;
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;
    ans.push_back(root->data);
    if (root->left)
        leftTransversal(root->left, ans);
    else
        leftTransversal(root->right, ans);
}
void leafTransversal(Node *p, vector<int> &ans)
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
    leafTransversal(root->left, ans);
    leafTransversal(root->right, ans);
}
void rightTransversal(Node *root, vector<int> &ans)
{

    if ((root == NULL) )
        return;
    if(root->left == nullptr && root->right == nullptr) return;
    if (root->right)
        rightTransversal(root->right, ans);
    else
        rightTransversal(root->left, ans);

    ans.push_back(root->data);
}
vector<int> boundary(Node *root)
{
    vector<int> ans;
    // left
    ans.push_back(root->data);
    leftTransversal(root->left, ans);
    // //leaf node
    leafTransversal(root->left, ans);
    leafTransversal(root->right, ans);
    // //right --> reverse
    rightTransversal(root->right, ans);
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