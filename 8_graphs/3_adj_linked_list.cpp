#include <bits/stdc++.h>
using namespace std;
#define V 5
class Node
{
public:
    int data;
    Node *next;
    Node(int ele)
    {
        data = ele;
        next = nullptr;
    }
};
Node *adjList[V];
void init()
{
    for(int i=0; i<V; i++)
    {
        adjList[i]=nullptr;
    }
}
void addEdge(int src, int dest,int ele)
{
    Node *n=new Node(ele);
    n->data = ele;
    n->next == nullptr;

    if(adjList[src]==nullptr)
        adjList[src]=n;
    else
    {
        Node *last = adjList[src];
        while(last->next!=nullptr)
        {
            last=last->next;
        }
        last->next=new Node(ele);
    }

}
void print_graph()
{
    for(int i=0; i<V; i++)
    {
        Node *temp = adjList[i];
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"NULL";
    }
}


int main()
{
    init();
    print_graph();
    return 0;
}