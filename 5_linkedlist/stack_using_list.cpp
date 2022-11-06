#include<bits/stdc++.h>
using namespace std;
class Node
{   public:
    int data;
    Node *next;
    Node *prev;
  
    Node(int data)
    {
        this->data=data;
        next=nullptr;
        prev=nullptr;
    }
};
class linkedlist
 
{    
     public:
     Node *head;
     Node *tail;
     int size;
        linkedlist()
        {
            head=nullptr;
            tail=nullptr;
            size=0;
        }
        void push_end(int ele)
        {
             Node *n= new Node (ele);
            if(tail==nullptr)
            {
                head=tail=n;
            }
            tail->next=n;
            n->prev=tail;
            tail=n;
            size=1;
            return;


        }
        void push_front(int ele)
        {
            Node *n=new Node(ele);
            if(head==nullptr)
            {
                tail=head=n;
            }
            head->prev=n;
            n->next=head;
            head=n;
            size=1;
            return;
        }
        void pop_front()
        {  Node *p=head;
            if(head==nullptr)
            {
                cout<<"underflow "<<endl;
                return;

            }
             
            head=head->next;
            head->prev = nullptr;
            size--; 

            if(head==nullptr)
            {
                tail=nullptr;
            }
        }
        void pop_end()
        {
            if(tail==nullptr)
            {
                cout<<"underflow "<<endl;
                return;
            }
            if(head==tail)
            {
                head=tail=nullptr;
                return;
            }
            tail = tail->prev;
             tail->next = nullptr;
        }
    int view_last()
    {
           if(tail==nullptr)
           {
               return -1;
           }
           return tail->data;
    }
    int view_front()
    {
            if(head==nullptr)
           {
               return -1;
           }
           return head->data;
    }
    void display_lst(){
                 
                Node *p=head;
                while(p!=nullptr)
                {  
                    cout<<p->data<<" ";
                   p=p->next;

                }


                      }
 
     
};

class Stack
{   
    // int ele;
    public:
    
    linkedlist l;
    void push(int ele)
    {
        l.push_end(ele);
    }
    void pop()
    {
        l.pop_end();
    }
    int top()
    {
        return l.view_last();
    }


};
int main()
{
   Stack s;
   s.push(10);
   s.push(20);
   s.pop();
   s.pop();
   s.pop();
   cout<<s.top();

    
     
    return 0;
}