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
//when the distance of left and right side will become same map will arrange them from left to right
void lo(Node *root , int hdis, map<int,vector<int>>&map)
{
    if(root == nullptr)return;
    map[hdis].push_back(root->val);
    
    lo(root->left , hdis+2, map);
    lo(root->right,hdis+2,map);
    
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

    int hdis=0;
    map<int,vector<int>>map;
    lo(root,hdis,map);
    for(auto it = map.begin(); it!=map.end(); it++)
    {
        for(int i=0; i<it->second.size(); i++)
        {
            cout<<(it->second)[i]<<" ";
        }
    }
}