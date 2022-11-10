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
void morrisTraversal(Node *root)
{
    if (root == nullptr)
        return;
    Node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left)
        {
            Node *predecessor = curr->left; // predecessor means phlele left fir jitna right ja skee
            
            while (predecessor->right && predecessor->right != curr)
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == nullptr)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
        else
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
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
    cout << "MorrisTraversal " << endl;
    morrisTraversal(root);
}