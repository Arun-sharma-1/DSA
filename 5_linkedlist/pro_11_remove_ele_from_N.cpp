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
        if (head == nullptr)
            return head;
        Node *p = head;
        while (p != nullptr)
        {
            p = p->next;
            count++;
        }
        p = head;
        if (count == 1)
        {
            head = nullptr;
            return head;
        }
        if (count == n)
        {
            return head->next;
        }
        for (int i = 0; i < count - n - 1; i++)
        {
            p = p->next;
        }
        p->next = p->next->next;
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