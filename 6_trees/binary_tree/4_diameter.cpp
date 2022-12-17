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


//ADITYA VERMA SOLN
int findDiameter(TreeNode *root , int &res)
{
    if(root == nullptr) return 0;
    int left = findDiameter(root->left , res);
    int right = findDiameter(root->right,res);
    
    int temp = 1+ max(left, right); //  root is also included so find max from left and right and add 1
    int ans = max(temp,1+left+right); // root is not included so add left path + right path + 1 node
    res= max(res,ans);
    return temp; // returning the temp calculated result in each step to find  maxm
}



int res = 0;
int fn(Node *root)
{
    if (root == nullptr)
        return 0;
    int x = fn(root->left);
    int y = fn(root->right);

    res = max(res, x + y + 1);
    return 1 + max(x, y);//ADDING NODE 
}
int diameter(Node *root)
{

    int answer = fn(root);
    return res;
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

    cout << diameter(root);
}