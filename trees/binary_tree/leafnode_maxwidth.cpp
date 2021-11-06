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
int leaf_node(Node *root)
{
    int x = 0, y = 0;
    int count = 0;
    if (root != nullptr)
    {
        x = leaf_node(root->left);
        y = leaf_node(root->right);
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
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    int res = 0;
    while (!q.empty())
    {
        int count = q.size();
        res = max(res, count);

        for (int i = 0; i < count; i++)
        {
            Node *p = q.front();
            q.pop();

            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
    cout << res;
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