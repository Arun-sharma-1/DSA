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
// Recursive
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// iterative
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
        stk.pop();
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
void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// preorder iterative
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

// iterative
// using two stack we can maintain the order of left right root
void postorderI(Node *root)
{
    stack<Node *> s;
    stack<Node *> out;
    s.push(root);

    while (!s.empty())
    {
        Node *p = s.top();
        s.pop();
        out.push(p);
        if (p->left)
            s.push(p->left);
        if (p->right)
            s.push(p->right);
    }
    while (!out.empty())
    {
        cout << out.top()->data << " ";
        out.pop();
    }
}
// using reverse -> easy code in postorder iterative
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> stk;
    if (root == nullptr)
        return res;
    stk.push(root);

    while (!stk.empty())
    {
        auto top = stk.top();
        stk.pop();

        res.push_back(top->val);

        if (top->left)
            stk.push(top->left);
        if (top->right)
            stk.push(top->right);
    }
    reverse(res.begin(), res.end());
    return res;
}
int Level_order(Node *root)
{
    if (root == nullptr)
        return -1;
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        if (p != nullptr)
        {
            cout << p->data << " ";
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        else if (!q.empty())
        {
            q.push(nullptr);
        }
    }
}
void Level_order_new(Node *root)
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
void levelorder(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
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
// working
void zigzagTree(Node *root)
{
    if (root == nullptr)
        return;
    int count = 0;
    queue<Node *> q;
    q.push(root);
    vector<int> ans;

    while (!q.empty())
    {
        count++;
        int size = q.size();
        vector<int> data(size);
        for (int i = 0; i < size; i++)
        {
            Node *p = q.front();
            q.pop();
            data[i] = p->data; // due to this in each index value will be updated after each loop
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        if (count % 2 == 0)
        {
            reverse(data.begin(), data.end());
            for (auto i : data)
                ans.push_back(i);
        }
        else
            for (auto i : data)
                ans.push_back(i);
    }
    for (auto ele : ans)
        cout << ele << " ";
}
// WORKING
vector<int> zigZagTraversal(Node *root)
{
    // Code here
    vector<int> result;
    queue<Node *> q;
    q.push(root);
    bool isRightDirection = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            Node *p = q.front();
            q.pop();
            int index = isRightDirection ? i : size - 1 - i;
            ans[index] = p->data;

            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        isRightDirection = !isRightDirection;
        for (auto i : ans)
            result.push_back(i);
    }

    return result;
}
// max value in tree
int max_value(Node *root)
{
    if (root == nullptr)
        return INT_MIN;
    int x = max_value(root->left);
    int y = max_value(root->right);
    return max(root->data, max(x, y));
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
    cout << "Inorder: " << endl;
    inorder_iter(root);
    cout << endl;
    cout << "Post order : " << endl;
    postorder(root);
    cout << endl;
    cout << "Pre order : " << endl;
    preorder(root);
    cout << endl;
    cout << "Zig Zag or spiral order " << endl;
    zigzagTree(root);
}