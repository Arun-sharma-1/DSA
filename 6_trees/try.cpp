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
        left=right=nullptr;
    }
};
class BST
{
    Node *root;
     void inorder_transversal(Node *root)
    {
        if(root==nullptr) return;
        inorder_transversal(root->left);
        cout<<root->data<<" ";
        inorder_transversal(root->right);
    }
    void postorder_transversal(Node *root)
    {
         if(root==nullptr) return;
        inorder_transversal(root->left);
        inorder_transversal(root->right);
        cout<<root->data<<" ";

    }
    void preorder_transversal(Node *root)
    {
         if(root==nullptr) return;
         cout<<root->data<<" ";
        inorder_transversal(root->left);
        inorder_transversal(root->right);
         
    }

    public:
    BST()
    {
        root=nullptr;
    }
    
    void inorder(){
        if(root==nullptr)
        {
            cout<<"tree is empty ";
        }
        cout<<"Inorder : ";
        inorder_transversal(root);
    }
    void postorder(){
        if(root==nullptr)
        {
            cout<<"tree is empty ";
        }
        cout<<"postorder : ";
        postorder_transversal(root);
    }
    void preorder(){
        if(root==nullptr)
        {
            cout<<"tree is empty ";
        }
        cout<<"Preorder : ";
        preorder_transversal(root);
    }
    // iteration 
    void insert_ele(Node *root,int ele)
    {
        if(root==nullptr)
        {
            root=new Node(ele);
            return;
        }
        if(ele<=root->data)
        {
            if(root->left==nullptr)
            {
                root->left=new Node(ele);
                return;
            }else insert_ele(root->left,ele);
            
            if(root->right==nullptr)
            return;
        }else insert_ele(root->right,ele);
        
    }
    void insert(int ele)
    {
        insert_ele(root,ele);
    }
    
};
int main()
{
    BST tree;
    vector<int> arr = {56,33,24,56,98,11,45,69,6,23,45,77,43};
    for(int ele:arr)
    {
        tree.insert(ele);
    }
    tree.inorder();
    tree.postorder();
    tree.preorder();

}