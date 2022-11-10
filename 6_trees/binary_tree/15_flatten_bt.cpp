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
void flatten(Node *root)
{
    // code here
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left)
        {
            Node *predecessor = curr->left;
            while (predecessor->right)
            {
                predecessor = predecessor->right;
            }
            predecessor->right = curr->right;
            curr->right = curr->left;
            // curr->left = nullptr; // breaking link can be done in this step also
        }
        curr = curr->right;
    }

    // to break the links
    curr = root;
    while (curr != nullptr)
    {
        curr->left = nullptr;
        curr = curr->right;
    }
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