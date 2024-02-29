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
    void createMapping(map<int, int> &map, int in[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            map[in[i]] = i;
        }
    }
    int findEle(int in[], int ele, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == ele)
                return i;
        }
        return -1;
    }
    Node *solve(int in[], int post[], int &index, int startIndex, int endIndex, int n)
    {
        if (index < 0 || startIndex > endIndex)
            return nullptr;

        int ele = post[index--];
        Node *root = new Node(ele);
        int position = findEle(in, ele, n);

        // recursive calls
        root->right = solve(in, post, index, position + 1, endIndex, n);
        root->left = solve(in, post, index, startIndex, position - 1, n);

        return root; // important step to make tree
    }
    Node *buildTree(int in[], int post[], int n)
    {
        // Your code here
        int index = n - 1;
        map<int, int> map;
        createMapping(map, in, n);
        Node *root = solve(in, post, index, 0, n - 1, n);
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
