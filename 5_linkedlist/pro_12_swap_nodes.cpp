//swap nth nodes form the starting and ending
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

      ListNode* swapNodes(ListNode* head, int k) {
        
        //ListNode *fast = head;
        // while(--k)
        // {
        //     fast= fast->next;
        // }
        // ListNode *first = fast;
        // ListNode *slow = head;
        
        // while(fast->next!=nullptr)
        // {
        //     fast= fast->next;
        //     slow=slow->next;
        // }
        
        // swap(slow->val,first->val);
        // return head;

        ListNode *temp = head;
        int count = 0;
        while(temp!=nullptr)
        {
            temp = temp->next;
            count++;
        }
        temp = head; 
        for(int i=1; i<k; i++)
        {
            temp =temp->next;
        }
        cout<<temp->val<<" temp";
        
        //get Nthe element from end 
        ListNode *slow =head;
        ListNode *fast = head;
        
        for(int i=0; i<k; i++)
        {
            fast=fast->next;
        }
    
        while(fast!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        cout<<slow->val;
        swap(temp->val , slow->val);
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