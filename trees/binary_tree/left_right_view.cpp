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
// left view of binary tree using recursion
// we will use preorder technique for this and pass level as 1 
// O(n)
int maxlevel=0; // important to make global 
void left_view(Node *root ,int level)
{
    if(root == nullptr) return;
    if(maxlevel < level)
    {
        cout<<root->data<<" ";
        maxlevel=level;
    }
    left_view(root->left , level+1);
    left_view(root->right , level+1);
}
// call like this --> left_view(root, 1);

void leftview_iterative(Node *root)
{
    if(root==nullptr) return;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
 
        for(int i=0; i<count; i++)
        {
            Node *p=q.front();
            q.pop();
            if(i==0) cout<<p->data<<" ";
        }
        if(leftview_iterative) q.push(root->left);
        if(leftview_iterative) q.push(root->right);
    }
}
void leftview_iterative(Node *root)
{
    if(root==nullptr) return;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
 
        for(int i=0; i<count; i++)
        {
            Node *p=q.front();
            q.pop();
            if(i==0) cout<<p->data<<" ";
         
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
        }
    }
}
void rightview_iterative(Node *root)
{
    if(root==nullptr) return;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
 
        for(int i=0; i<count; i++)
        {
            Node *p=q.front();
            q.pop();
            if(i==n-1) cout<<p->data<<" ";
         
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
        }
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

    // preorder(root);
    // cout << endl;
    // inorder_iter(root);
    // cout << endl;
    // postorder_iter(root);
    // cout << endl;
    // cout<<sum(root);

    Level_order(root);
}