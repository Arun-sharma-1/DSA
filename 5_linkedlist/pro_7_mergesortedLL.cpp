#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
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
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    int view_front()
    {
        if (head == nullptr)
        {
            cout << "here " << endl;
            return -1;
        }
        return head->data;
    }
    void push_end(int ele)
    {
        Node *n = new Node(ele);
        if (tail == nullptr)
        {
            head = n;
            tail = n; // first n is assigned to tail then result is assigned to head
            return;
        }
        tail->next = n;
        tail = n;
        size++;
        return;
    }
    void push_front(int ele)
    {
        Node *n = new Node(ele);
        if (head == nullptr)
        {
            tail = head = n;
            return;
        }
        n->next = head;
        head = n;
        size++;
    }
    void display_lst(Node *head)
    {
        Node *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    Node *mergeTwoList(Node *a, Node *b)
    {
        Node *head;
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;
        if (a->data < b->data)
        {
            head = tail = a;
            a = a->next;
        }
        else
        {
            head = tail = b;
            b = b->next;
        }
        while (a != nullptr && b != nullptr)
        {
            if (a->data >= b->data)
            {
                tail->next = b;
                tail = b;
                b = b->next;
            }
            else
            {
                tail->next = a;
                tail = a;
                a = a->next;
            }
        }

        if (a == nullptr)
            tail->next = b;
        else
            tail->next = a;
        return head;
    }
    Node *sortedMerge(Node *head1, Node *head2)
    {
        // code here
        Node *head;
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;
        Node *tail; // just to get the head 
        if (head1->data > head2->data)
        {
            head = head2;
            tail = head2;
            head2 = head2->next;
        }
        else
        {
            head = head1;
            tail = head1;
            head1 = head1->next;
        }
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->data > head2->data)
            {
                head->next = head2;
                head2 = head2->next;
            }
            else
            {
                head->next = head1;
                head1 = head1->next;
            }
            head = head->next;
        }
        while (head1 != nullptr)
        {
            head->next = head1;
            head1 = head1->next;
            head = head->next;
        }
        while (head2 != nullptr)
        {
            head->next = head2;
            head2 = head2->next;
            head = head->next;
        }

        return tail;
    }
};
int main()
{
    linkedlist lst;
    lst.push_end(20);
    lst.push_end(30);
    lst.push_end(40);
    // lst.display_lst(lst.head);

    linkedlist lst2;
    lst2.push_end(5);
    lst2.push_end(6);

    Node *start = lst.mergeTwoList(lst.head, lst2.head);
    while (start != nullptr)
    {
        cout << start->data << ",";
        start = start->next;
    }

    return 0;
}