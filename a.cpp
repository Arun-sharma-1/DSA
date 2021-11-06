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
        data = ele;
        left = right = nullptr;
    }
};

class BST
{
    Node *root;
    void inorder_transversal(Node *root)
    {
        if (root == nullptr)
            return;
        inorder_transversal(root->left);
        cout << root->data << " ";
        inorder_transversal(root->right);
    }
    void preorder_transversal(Node *root)
    {

        if (root == nullptr)
            return;
        cout << root->data << " ";
        preorder_transversal(root->left);
        preorder_transversal(root->right);
    }

    void postorder_transversal(Node *root)
    {
        if (root == nullptr)
            return;
        postorder_transversal(root->left);
        postorder_transversal(root->right);
        cout << root->data << " ";
    }

public:
    BST()
    {
        root = nullptr;
    }
    Node *insert_ele(Node *root , int ele)
    {
        if(root==nullptr)
            return new Node(ele);
        if(ele <= root->data)
            root->left=insert_ele(root->left ,ele);
        else root->right=insert_ele(root->right,ele);

        
    }
    void insert(int ele)
    {
        root=insert_ele(root, ele);
    }
    bool ispresent(Node *root) {}

    void inorder()
    {
        inorder_transversal(root);
    }
    void postorder()
    {
        postorder_transversal(root);
    }
    void preorder()
    {
        preorder_transversal(root);
    }
};

int main()
{
    BST tree;
    vector<int> arr = {12, 423, 1, 34, 2, 5, 9, 90, 3};
    for (auto ele : arr)
    {
        tree.insert(ele);
    }
    tree.inorder();
}
