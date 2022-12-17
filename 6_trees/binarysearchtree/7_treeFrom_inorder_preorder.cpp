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
    // CREATE TREE FROM INORDER AND PREORDER
    int findEle(int in[], int ele, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == ele)
                return i;
        }
        return -1;
    }
    Node *solve(int in[], int pre[], int &index, int startIndex, int endIndex, int n)
    {
        if (index >= n || startIndex > endIndex)
            return nullptr;
        int firstEle = pre[index++];
        Node *root = new Node(firstEle);

        int indexEle = findEle(in, firstEle, n);
        root->left = solve(in, pre, index, startIndex, indexEle - 1, n);
        root->right = solve(in, pre, index, indexEle + 1, endIndex, n);
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int Index = 0;
        Node *root = solve(in, pre, Index, 0, n - 1, n);
        return root;
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
