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
    void inorder(Node *root, vector<int> &v)
    {
        if (root == nullptr)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    Node *createBST(int s, int e, vector<int> v)
    {
        if (s > e)
            return nullptr;
        int mid = (s + e) / 2;
        Node *root = new Node(v[mid]);
        root->left = createBST(s, mid - 1, v);
        root->right = createBST(mid + 1, e, v);

        return root;
    }
    Node *buildBalancedTree(Node *root)
    {
        // Code here
        vector<int> v;
        inorder(root, v);
        return createBST(0, v.size() - 1, v);
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
    if (root == nullptr)
        return true;
    return isbinary(root, INT_MIN, INT_MAX);
}
