#include <bits/stdc++.h>
using namespace std;
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

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = nullptr;
    }
    void push_end(int ele)
    {
        Node *n = new Node(ele);
        if (tail == nullptr)
        {
            head = tail = n;
            return;
        }
        tail->next = n;
        tail = n;
        // size=1;
        return;
    }
    Node *removeNthFromEnd(ListNode *head, int n)
    {

        // USING TWO POINTER APPPROCH
        //  ListNode *slow = head;
        // ListNode *fast = head;
         
        // for(int i=0; i<n; i++)
        // {
        //     fast=fast->next;
        // }
        // if(fast == nullptr) return head->next;
        // while(fast->next!=nullptr)
        // {
        //     slow=slow->next;
        //     fast=fast->next;
        // }
        // slow->next = slow->next->next;
        // return head;


       int count = 0;
        ListNode *temp = head;
        
        while(temp != nullptr)
        {
            temp = temp->next;
            count++;
        }
        
        int fromFront = count - n;
        if(fromFront == 0) return head->next;
        temp = head;
        for(int i=0; i<fromFront-1; i++)
        {
            temp = temp->next;
        }
        temp->next =temp->next->next;
        return head;

    }
    

    void display_lst()
    {
        Node *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
};
int main()
{
    LinkedList lst;
    lst.push_end(10);
    lst.insert(1, 1);
    lst.insert(2, 2);
    lst.insert(3, 3);

    lst.insert(12, 2);

    lst.display_lst();
}