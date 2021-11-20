#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
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
void preorder_iter(Node *root)
{
    Node *p = root;
    stack<Node *> s;

    while (p != nullptr || !s.empty())
    {
        while (p != nullptr)
        {
            s.push(p);
            cout << p->data << " ";
            p = p->left;
        }
        p = s.top();
        s.pop();
        p = p->right;
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
void inorder_iter(Node *root)
{
    Node *p = root;
    stack<Node *> stk;
    while (p != nullptr || !stk.empty())
    {
        while (p != nullptr)
        {
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        cout << p->data << " ";
        stk.pop();
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
    }
}
void level_order(Node *root)
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
            Node *curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}
int count_nodes(Node *root)
{
    if (root == nullptr)
        return 0;
    int x = count_nodes(root->left);
    int y = count_nodes(root->right);
    return x + y + 1;
}
int sum_nodes(Node *root)
{
    if (root == nullptr)
        return 0;
    int x = sum_nodes(root->left);
    int y = sum_nodes(root->right);
    return x + y + root->data;
}
int height(Node *root)
{
    int x, y;
    if (root == nullptr)
        return 0;
    x = height(root->left);
    y = height(root->right);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int Nodes_with_0degree(Node *root)
{
    int x, y;
    if (root == nullptr)
        return 0;
    x = Nodes_with_0degree(root->left);
    y = Nodes_with_0degree(root->right);
    if (!root->left && !root->right)
        return x + y + 1;
    else
        return x + y;
}
void print(Node *root, int k)
{
    if (root == nullptr)
        return;
    if (k == 0)
        cout << root->data << " ";
    else
    {
        print(root->left, k - 1);
        print(root->right, k - 1);
    }
}
int max_value(Node *root)
{
    if (root == nullptr)
        return 0;
    int x = max_value(root->left);
    int y = max_value(root->right);

    return max(root->data, max(x, y));
}
void left_view(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

bool children_sum(Node *root)
{
    int sum = 0;
    if (root == nullptr)
        return true;
    if (root->left == nullptr && root->right == nullptr)
        return true;
    if (root->left)
        sum += root->left->data;
    if (root->right)
        sum += root->right->data;
    return (root->data && children_sum(root->left) && children_sum(root->right));
}
int max_width(Node *root)
{
    int res = 0;
    if (root == nullptr)
        return 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        res = max(res, size);
        cout<< res<<" ";
         
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
//    cout<< res;
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

    max_width(root);
    // cout << "Preorder: ";
    // preorder(root);
    // cout << endl;
    // cout << "Inorder: ";
    // inorder_iter(root);
    // cout << endl;
    // cout << "preorder:";
    // postorder(root);
    // cout << endl;
    // cout << "Level Order: ";
    // level_order(root);
}