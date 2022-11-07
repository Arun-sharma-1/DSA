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
void topView(Node *root)
{
    if(root == nullptr)return;
    map<int,int>treeNode;//track of hdis(horizontal distance) and node data
    queue<pair<Node * ,int >>q;
    q.push(make_pair(root,0));//data and hdis
    while(!q.empty())
    {
        pair<Node *,int>temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hdis=temp.second;
        if(treeNode.find(hdis) == treeNode.end())
        {
            treeNode[hdis]=frontNode->data;
        }
        if(frontNode->left)q.push(make_pair(frontNode->left,hdis-1));
        if(frontNode->right)q.push(make_pair(frontNode->right,hdis+1));
    }
    for(auto it=treeNode.begin(); it!=treeNode.end(); it++)
    {
        cout<<it->second<<" ";
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

    topView(root);
    
}