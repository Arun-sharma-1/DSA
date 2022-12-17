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

public:
    BST()
    {
        root = nullptr;
    }

    Node *insert_ele(Node *root, int ele)
    {
        if (root == nullptr)
            return new Node(ele);
        if (ele <= root->data)
            root->left = insert_ele(root->left, ele);
        else
            root->right = insert_ele(root->right, ele);
    }

    void insert(int ele)
    {
        root = insert_ele(root, ele);
    }

    int min_value()
    {
        if (root == nullptr)
            return -1;

        while (root != nullptr)
        {
            root = root->left;
            cout << root->data << " ";
        }
    }
    int max_value()
    {
        if (root == nullptr)
            return -1;
        while (root != nullptr)
        {
            root = root->right;
            cout << root->data << " ";
        }
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
    tree.min_value();
    tree.max_value();
}
