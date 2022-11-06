#include<bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node *next;
    public:
    Node(int ele)
    {
        this->data = ele;
        next = nullptr;
    }
}
class CircluarList
{
    Node *head;
    Node *tail;
    public:
    CircluarList()
    {
        head = tail = nullptr;
    }
    void push_end(int ele)
    {
        Node *n = new Node(ele);
        if(head == nullptr)
        {
            n->next = n;
            return;
        }
        Node *p = head;
        
    }
    void display()
    {

    }

}
int main()
{
    return 0;
}