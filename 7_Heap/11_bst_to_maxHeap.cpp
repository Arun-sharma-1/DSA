#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void inorder(Node *root, vector<int> &v)
    {
        Node *p = root;
        stack<Node *> s;
        while (p != nullptr || !s.empty())
        {

            while (p != nullptr)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            v.push_back(p->data);
            p = p->right;
        }

        // if(root == nullptr) return;
        // inorder(root->left , v);
        // v.push_back(root->data);
        // inorder(root->right,v);
    } // 1 2 3 4 5
    void insertHeap(Node *root, int &index, vector<int> &v)
    {
        if (root == nullptr || index < 0)
            return;
        insertHeap(root->left, index, v);
        insertHeap(root->right, index, v);
        root->data = v[index++];
    }
    void convertToMaxHeapUtil(Node *root)
    {
        // Your code goes here
        vector<int> v;
        inorder(root, v);
        int lastIndex = 0;
        insertHeap(root, lastIndex, v);
    }
};

int main()
{
    /*
    If you want to convert bst to max heap then , store the inorder in array and the use postorder because the minim value will be at the bottom
    If you want to convert bst to min heap then , store the inorder in array and  then use preorder
    */
}