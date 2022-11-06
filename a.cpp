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
void inorder_itr(Node *root)
{
    Node *p = root;
    stack<Node *> s;
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
void inorderitrr(Node *root)
{
    // left root right node
    if (root == nullptr)
        return;
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

void preorder_iterative(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *p = s.top();
        s.pop();
        cout << p->data << " ";
        // pushing right first bacasue then stack will contain left most on top
        if (p->right != nullptr)
            s.push(p->right);
        if (p->left != nullptr)
            s.push(p->left);
    }
}
void preo_itr(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *p = s.top();
        s.pop();
        cout << p->data << " ";
        if (p->right != nullptr)
            s.push(p->right);
        if (p->left != nullptr)
            s.push(p->left);
    }
}
void postorder_iter(Node *root)
{
    Node *p = root;
    stack<Node *> s;
    while (p != nullptr || !s.empty())
    {
        while (p != nullptr)
        {
            p = p->left;
            s.push(p);
        }
        p = s.top();
        while (p != nullptr)
        {
            p = p->right;
            s.push(p);
        }
        p = s.top();
        s.pop();
        cout << p->data << " ";
        p = s.top();
    }
}

void levelorder(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *p = q.front();
            q.pop();

            cout << p->data << " ";
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
}
int countNode(Node *root, int k)
{
    // nodes at k distance
    if (root == nullptr)
        return 0;
    if (k == 0)
        cout << root->data;
    else
    {
        countNode(root->left, k - 1);
        countNode(root->right, k - 1);
    }
}
void lo(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
}
int Sum_Node(Node *root)
{
    int x = 0, y = 0;
    if (root == nullptr)
        return 0;
    x = Sum_Node(root->left);
    y = Sum_Node(root->right);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
void levor(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
}
void leftview(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *p = q.front();
            q.pop();
            if (i == size-1)
                cout << p->data << " ";
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
}
void maxmWidth(Node *root)
{
    if(root == nullptr) return;
    queue<Node *>q;
    int res=0;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        res = max(res , size);
        cout<<"size  --> "<<size<<endl;
        for(int i=0; i<size; i++)
        {
            Node *p = q.front();
            q.pop();
            if(p->left)q.push(p->left);
            if(p->right)q.push(p->right);
        }
    }
    cout<<res;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(11);

    root->right = new Node(3);
    root->right->left = new Node(9);
    root->right->left->left = new Node(10);

    root->right->right = new Node(5);
    root->right->right->left = new Node(6);
    root->right->right->left->left = new Node(8);
    root->right->right->left->right = new Node(9);

    root->right->right->right = new Node(7);
    maxmWidth(root);
    return 0;
}