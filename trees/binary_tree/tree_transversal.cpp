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
        left=right=nullptr;
        data=ele;
    }

};
// Recursive 
void inorder(Node *root)
{
    if(root==nullptr)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// iterative 
void inorder_iter(Node *root)
{
    Node *p=root;
    stack<Node *>stk;
    while(p!=nullptr || !stk.empty())
    {
     
        while(p!=nullptr)
        {
            stk.push(p);
            p=p->left;
        }
        p=stk.top();
        stk.pop();
        cout<<p->data<<" ";
        p=p->right;
        }
    
    }
void  postorder(Node *root)
{
    if(root==nullptr)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preorder(Node *root)
{
    if(root==nullptr)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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
    if(root==nullptr) return;
    queue<Node *>q;
    q.push(root);
    
    
    while(!q.empty())
    {
        Node *p=q.front();
        q.pop();
            cout<<p->data<<" ";
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
             
    }
}
void levelorder(Node *root)
{
    if(root==nullptr) return;
    queue<Node *>q ;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        for(int i=0; i<count; i++)
        {
            Node *p=q.front();
            q.pop();
            cout<<p->data<<" ";
            
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
    }
}
// max value in tree
int max_value(Node *root)
{
    if(root==nullptr) return INT_MIN;
    int x=max_value(root->left);
    int y=max_value(root->right);
    return max(root->data , max(x,y));
}




int main()
{    
    Node *root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(11);

    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->left->left=new Node(10);
    root->right->right = new Node(5);

    root->right->right->left=new Node(6);
    root->right->right->left->left=new Node(8);
    root->right->right->left->right=new Node(9);

    root->right->right->right=new Node(7);
    cout<<"Inorder: "<<endl;
    inorder_iter(root);
    cout<<endl;
    cout<<"Post order : "<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Pre order : "<<endl;
    preorder(root);

    

}