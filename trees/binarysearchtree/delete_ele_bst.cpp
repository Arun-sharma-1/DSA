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

    Node *getsuccessor(Node *root)
    {
        root = root->right;
        while (root != nullptr && root->left != nullptr)
            root = root->left;
        return root;
    }
    Node *delele(Node *root, int ele)
    {
        if (root == nullptr)
            return root;
        if (ele < root->data)
            root->left = delele(root->left, ele);
        else if (ele > root->data)
            root->right = delele(root->right, ele);
        else
        {
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                free(root);
                return temp;
            }
            else
            {
                Node *succ = getsuccessor(root);
                root->data = succ->data;
                root->right = delele(root->right, succ->data);
            }
            return root;
        }
    }

    void delete_node(int ele)
    {
        root = delele(root, ele);
    }

    void inorder()
    {
        inorder_transversal(root);
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
    cout << endl;
    tree.delete_node(12);
    tree.inorder();
}
