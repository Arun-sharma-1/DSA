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
void preorder(Node *root)
{

    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void inorder_iter(Node *root)
{
    stack<Node *> s;
    Node *p = root;
    while (p != nullptr || !s.empty())
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();

        cout << p->data << " ";
        p = p->right;
    }
}
void postorder(Node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void postorder_iter(Node *root)
{
    stack<Node *> s;
    Node *p = root;
    while (p != nullptr || !s.empty())
    {
        while (p != nullptr)
        {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();

        p = p->right;
        cout << p->data << " ";
    }
}
void Level_order(Node *root)
{
    if(root==nullptr) return;
    queue<Node *>q;
    q.push(root);
    q.push(nullptr);
 vector<int>v;
 v.push_back
    while(!q.empty())
    {
        Node *p=q.front();
        q.pop();

        if(p!=nullptr) 
        {
            cout<<p->data<<" ";
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);

        }
        else if(!q.empty()) q.push(nullptr);
    }
}

int nodes_two_degree(Node *root)
{
    int x = 0, y = 0;
    if (root != nullptr)
    {
        x = count_node(root->left);
        y = count_node(root->right);
        if (root->left && root->right)
            return x + y + 1;
        else
            return x + y;
    }
    
    return 0;
}
int leaf_node(Node *root)
{
    int x = 0, y = 0;
    int count = 0;
    if (root != nullptr)
    {
        x = count_node(root->left);
        y = count_node(root->right);
        if (x == 0 && y == 0)
        {
            count++;
            cout << count << " ";
        }
    }
    else
        return 0;
}
void max_width(Node *root)
{
    if(root==nullptr) return;
    queue<Node *>q;
    q.push(root);
    int res=0;
    while(!q.empty())
    {
        int count=q.size();
        res=max(res,count);
 
        for(int i=0; i<count; i++)
        {
            Node *p=q.front();
            q.pop();
           
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        
        }
    }
    cout<<res;
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