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
    int count = 0;
    void Kth_smallest_element(Node *root, int k)
    {
        if (root == nullptr)
            return;
        Kth_smallest_element(root->left, k);
        count++;
        if (k == count)
            cout << root->data << " ";
        Kth_smallest_element(root->right, k);
    }
    void inorder(int k)
    {
        Kth_smallest_element(root, k);
    }
    /*
    int count = 0;
    int ans = -1;
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k)
    {
        // add code here.
        if (root == nullptr)
            return ans;
        KthSmallestElement(root->left, k);
        count++;
        if (k == count)
            ans = root->data;
        // cout<<root->data<<" ";
        KthSmallestElement(root->right, k);
        return ans;
    }*/
};

int main()
{
    BST tree;
    vector<int> arr = {12, 423, 1, 34, 2, 5, 9, 90, 3};
    for (auto ele : arr)
    {
        tree.insert(ele);
    }
    tree.inorder(8);
}
