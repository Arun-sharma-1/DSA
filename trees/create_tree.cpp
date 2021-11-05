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
        data=ele;
    }
};
int create()
{
     int x;
    Node *p,*t;
    queue<int>q;
    cout<<"Enter root value "<<endl;
    cin>>x;
    Node *root=new Node(x);
    q.push(root);

    while(!q.empty())
    {
        p=q.pop();
        cout<<"Enter left child "<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node(x);
            t->data=x;
            t->left = t->right =nullptr
            p->left=t;
            q.push(t);

        }
        cout<<"Enter right  child of " <<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node(x);
            t->data=x;
            t->left = t->right =nullptr
            p->right=t;
            q.push(t);

        }
    }
}
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    create();
     
    
}