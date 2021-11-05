 #include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int data;
    Node *next;
    int size;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
        size=0;
    }

};
class Linkedlist
{
    Node *head;
    Node *tail;
    public:
    Linkedlist()
    {
          head=nullptr;
            tail=nullptr;
    }

    void push_back(int ele)
    {
        Node *n=new Node(ele);
        if(tail==nullptr)
        {
            head=tail=n;
    
        }
        tail->next=n;
        tail=n;
    }

    int display_lst()
    {
        Node *p=head;
        while(p!=nullptr)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
    }
};
int main()
{
    Linkedlist lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

     
  

    lst.display_lst();
    return 0;
}