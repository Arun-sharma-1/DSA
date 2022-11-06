#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int ele)
    {
        left=right=nullptr;
        data=ele;
    }

};
int count_node(Node *root)
{
    int x = 0, y = 0;
    if (root != nullptr)
    {
        x = count_node(root->left);
        y = count_node(root->right);
        return x + y + 1;
    }
    return 0;
}

int nodes_with_two_degree(Node *root)
{
    int x = 0, y = 0;
    if (root != nullptr)
    {
        x = nodes_with_two_degree(root->left);
        y = nodes_with_two_degree(root->right);
        if (root->left && root->right)
            return x + y + 1;
        else
            return x + y;
    }
    
    return 0;
}
//Print nodes at distance k 
void print(Node *root ,int k)
{
    if(root==nullptr) return;
    if(k==0) cout<<root->data<<" ";
    else
    {
            print(root->left,k-1);
            print(root->right ,k-1);
    }
    
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);

    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    root->right->left->left = new Node(50);
    root->right->left->right = new Node(60);
    root->right->left->left->left = new Node(70);

    root->right->left->right->right = new Node(80);
    root->right->left->right->right->left = new Node(90);

     
}