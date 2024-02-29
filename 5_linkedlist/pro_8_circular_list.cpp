#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next; // self refrencing , which contain address
    Node(int ele)
    {
        this->data = ele;
        next = nullptr;
    }
};
void insertAtTail(Node *&head, int ele) // & is needed if we using functions instead of class
{
    Node *n = new Node(ele);
    // empty list
    if (head == nullptr)
    {
        // n->next = n; ??????? 
        head = n;
        return;
    }
    // list contain elements
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void insertAtHead(Node *&head, int ele)
{
    Node *temp = head;
    Node *n = new Node(ele);
    if (head == nullptr)
    {
        n->next = n;
        head = n;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void display(Node *head)
{
    // 1. Transversal using for loop 

    /*
    
    if(head == nullptr) return;
    cout<<head->data<<" ";
    for(Node *p = head->next; p!=head; p=p->next)
    {
        cout<<p->data<<" ";
    }

    */

    // do- while is nessacary for
    Node *temp = head;
    //  while(temp!= head) or while(temp->next != head)  // these both conditions won't work
    // if (head == nullptr)
    //     return;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != head);
}
void deleteAtHead(Node *&head, int posn)
{
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *toDelete = head;
    temp->next = head->next;
    head = head->next;

    // delete toDelete;
}
void deletion(Node *&head, int posn)
{
    // if head is to be deleted
    if (posn == 1)
    {
        deleteAtHead(head, posn);
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count != posn - 1)
    {
        temp = temp->next;
        count++;
    }

    Node *toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}
int main()
{
    Node *head = nullptr;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);

    display(head);
    insertAtTail(head, 4);
    cout << endl;
    deletion(head, 4);
    deletion(head, 1);
    display(head);
    return 0;
}