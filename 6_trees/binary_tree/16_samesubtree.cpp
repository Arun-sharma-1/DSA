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
//Check if subtree on GFG
//given two tree , T ans S is S is a part of tree T
bool isSame(Node *T , Node *S)
{
    // for leaf nodes
    if(!T && !S)return true;
    if(!T || !S || T->data != S->data) return false;

    return isSame(T->left,S->left) && isSame(T->right,S->right);
}
bool isSubTree(Node *T , Node *S)
{
    if(!S)return true;
    if(!T)return false;

    if(isSame(T,S)) return true;
    return isSubTree(T->left,S) || isSubTree(T->right,S);  
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
    
}