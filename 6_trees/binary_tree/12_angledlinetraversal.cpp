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
//Diagonal Traverse of Binary Tree
vector<int> diagonal(Node *root)
{
    // your code here
    vector<int> res;
    if (root == nullptr)
        return res;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        while (node)
        {
            if (node->left)
                q.push(node->left);
            res.push_back(node->data);
            node = node->right;
        }
    }
    return res;
}
void boundarytransverse(Node *root, int hdis, map<int, vector<int>> &map)
{
    if (root == nullptr)
        return;
    map[hdis].push_back(root->data);
    // it is same as vertical traveral it only depends how u insert item in map , so we are here playing just with horizontal dis
    boundarytransverse(root->left, hdis + 1, map);
    boundarytransverse(root->right, hdis, map);
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

    map<int, vector<int>> map;
    boundarytransverse(root, 0, map);
    for (auto it = map.begin(); it != map.end(); it++)
    {
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout << (it->second)[i] << " ";
        }
    }
}