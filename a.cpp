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

class BST
{
    Node *root;
    void inorder_transversal(Node *root)
    {
        if (root == nullptr)
            return;
        inorder_transversal(root->left);
        cout << root->data << " ";
        inorder_transversal(root->right);
    }
    void preorder_transversal(Node *root)
    {

        if (root == nullptr)
            return;
        cout << root->data << " ";
        preorder_transversal(root->left);
        preorder_transversal(root->right);
    }

    void postorder_transversal(Node *root)
    {
        if (root == nullptr)
            return;
        postorder_transversal(root->left);
        postorder_transversal(root->right);
        cout << root->data << " ";
    }

public:
    BST()
    {
        root = nullptr;
    }
    bool search(Node *root , int ele)
    {
       
        if(root==nullptr) return false; 
        
        if(ele == root->data) return true;
        if(ele < root->data) return search(root->left ,ele);
        else if(ele > root->data) return search(root->right ,ele);
        
    }
    bool search_itr(Node *root , int ele )
    {
        
        while(root!=nullptr)
        {
            if(ele == root->data) return true;
            if(ele < root->data) 
            {
                root=root->left;
            }
            else root=root->right;
        }
        return false;
    }
    void search_ele(int ele)
    {
        if(root==nullptr)
        {
            cout<<"Tree is empty ";
            return;
        }
        if(search_itr(root ,ele)) 
        {
            cout<<"Ele is present ";
        }
        else cout<<"ele is not present";
    }
    Node *insert_ele(Node *root , int ele)
    {
        if(root==nullptr)
            return new Node(ele);
        if(ele <= root->data)
            root->left=insert_ele(root->left ,ele);
        else root->right=insert_ele(root->right,ele);

        
    }

    void insert(int ele)
    {
        root=insert_ele(root, ele);
    }


    void inorder()
    {
        inorder_transversal(root);
    }
    void postorder()
    {
        postorder_transversal(root);
    }
    void preorder()
    {
        preorder_transversal(root);
    }
};

int main()
{
    BST tree;
    vector<int> arr = {12, 423, 1, 34, 2, 5, 9, 90, 3};
    for (auto ele : arr)
    {
        tree.insert(ele);
    }
    tree.inorder();
    cout<<endl;
    tree.search_ele(1);
}
