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
    void postorder_transversal(Node *root)
    {

        if (root == nullptr)
            return;
        postorder_transversal(root->left);
        postorder_transversal(root->right);
        cout << root->data << " ";
    }
    void preorder_transversal(Node *root)
    {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        preorder_transversal(root->left);
        preorder_transversal(root->right);
    }

public:
    BST()
    {
        root = nullptr;
    }

    // we are creating these coz we don't have access to root
    void inorder()
    {
        if (root == nullptr)
        {
            cout << "tree is empty ";
            return;
        }
        cout << "Inorder: ";
        inorder_transversal(root);
        //  inorder_itr(root);
    }

    void postorder()
    {
        if (root == nullptr)
        {
            cout << "tree is empty ";
            return;
        }
        cout << "Postorder: ";
        postorder_transversal(root);
    }

    void preorder()
    {
        if (root == nullptr)
        {
            cout << "tree is empty ";
            return;
        }
        cout << "Preorder: ";
        preorder_transversal(root);
    }

    // RECURSION-1 // not working
    //  void insertele(Node *root, int ele)
    //  {
    //     if(root==nullptr)
    //     {
    //         root=new Node(ele);
    //         return;
    //     }
    //  if(ele<=root->data)
    //  {
    //      if(root->left==nullptr)
    //      {
    //          root->left=new Node(ele);
    //      }else insertele(root->left,ele);
    //  }
    //  else{
    //      if(root->right==nullptr)
    //      {
    //          root->right=new Node(ele);
    //      }else insertele(root->right,ele);
    //  }
    //  }
    //  void insert(int ele)
    //  {
    //      insertele(root,ele);
    //  }

    //  RECURSION-2
    Node *insert_ele_rec(Node *root, int ele)
    {
        if (root == nullptr)
        {
            return new Node(ele); // creating new node and returnig the add of new node that we are inserting
        }
        if (ele <= root->data)
        {
            root->left = insert_ele_rec(root->left, ele); // connection nodes with each other
        }
        else
            root->right = insert_ele_rec(root->right, ele); // connection nodes with each other

        return root; // in this step we got root of tree(top most ele in tree)
    }

    void insert(int ele)
    {
        root = insert_ele_rec(root, ele);
    }

    bool search_itr(Node *root, int ele)
    {

        while (root != nullptr)
        {
            if (ele == root->data)
                return true;
            if (ele < root->data)
            {
                root = root->left;
            }
            else
                root = root->right;
        }
        return false;
    }

    bool node_present(Node *root, int ele)
    {
        if (root == nullptr)
            return false;
        if (ele == root->data)
            return true;

        if (ele <= root->data)
        {
            return node_present(root->left, ele);
        }
        else
            return node_present(root->right, ele);
    }

    void is_present(int ele)
    {
        if (node_present(root, ele))
        {
            cout << ele << " present" << endl;
        }
        else
        {
            cout << ele << " not present" << endl;
        }
    }

    // iteration
    void insert_ele(int ele)
    {
        Node *p = root;
        Node *n = new Node(ele);
        if (root == nullptr)
        {
            root = n; // p=n is wrong
            return;
        }
        while (p != nullptr)
        {
            if (ele <= p->data)
            {
                if (p->left == nullptr)
                {
                    p->left = n;
                    return;
                }
                p = p->left;
            }
            else
            {
                if (p->right == nullptr)
                {
                    p->right = n;
                    return;
                }
                p = p->right;
            }
        }
    }
};
int main()
{
    BST tree;
    vector<int> arr = {56, 33, 24, 56, 98, 11, 45, 69, 6, 23, 45, 77, 43};
    for (int ele : arr)
    {
        tree.insert(ele);
    }
    tree.inorder();
    cout << endl;
    tree.postorder();
    cout << endl;
    tree.preorder();
    cout << endl;
    tree.is_present(98);
}