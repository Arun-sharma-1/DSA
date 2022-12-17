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

    // void naiveMethod(Node *root, vector<int> &ans)
    // {
    //     if (root == nullptr)
    //         return;
    //     solve(root->left, ans);
    //     ans.push_back(root->data);
    //     solve(root->right, ans);
    // }
    bool isbinary(Node *root, int min, int max)
    {
        if (root == nullptr)
            return true;
        if (root->data >= min && root->data <= max)
        {
            bool left = isbinary(root->left, min, root->data);
            bool right = isbinary(root->right, root->data, max);
            return left && right;
        }
        else
            return false;
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
