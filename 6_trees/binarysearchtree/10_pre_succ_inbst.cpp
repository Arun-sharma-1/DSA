#include <bits/stdc++.h>

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // Write your code here.

    BinaryTreeNode<int> *temp = root;
    int pre = -1;
    int succ = -1;
    // find key
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pre = temp->data;
            temp = temp->right;
        }
    }
    // find pre
    BinaryTreeNode<int> *leftSubTree = temp->left;

    while (leftSubTree != nullptr)
    {
        pre = leftSubTree->data;
        leftSubTree = leftSubTree->right;
    }

    // find succ
    BinaryTreeNode<int> *rightSubTree = temp->right;

    while (rightSubTree != nullptr)
    {
        succ = rightSubTree->data;
        rightSubTree = rightSubTree->left;
    }
    return {pre, succ};
}

int main()
{

    return 0;
}