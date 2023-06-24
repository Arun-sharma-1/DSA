 #include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int ele)
    {
        data=ele;
        next=nullptr;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;
    public:
    LinkedList()
    {
        head=tail=nullptr;
    }
    void push_end(int ele)
        {
             Node *n= new Node (ele);
            if(tail==nullptr)
            {
                head=tail=n;
                return;
            }
            tail->next=n;
            tail=n;
            // size=1;
            return;


        }
    //geeky shows 
    void insert(int data, int n)
    {
        Node *temp1=new Node(data);
        
        if(n==1)
        {
            temp1->next=head;
            head=temp1;
            return;
        }
    // iterating to n-2 coz we have to stop before that node 
    // temp2 is the node before where we want to insert
    // we are swapping address to insert ele in linked list 
        Node *temp2=head;
        for(int i=0; i<n-2; i++)
        {
            temp2=temp2->next;
        }
        temp1->next=temp2->next;
        temp2->next=temp1;

        // if(n > size +1 )
        // {
        //     cout<<" invalid n ";
        //     return;
        // }
    }

  

    void display_lst()
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
    LinkedList lst;
    lst.push_end(10);
    lst.insert(1,1);
    lst.insert(2,2);
    lst.insert(3,3);
     
    lst.insert(12,2);

    lst.display_lst();
}  