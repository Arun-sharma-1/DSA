#include <bits/stdc++.h>
using namespace std;
// self referential class that contain the data memeber as a pointer which contain the address of the object of this class
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
// when we are creating new node then we create two things data and address in the first node
// we point address to 0 and then we update it
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
    void push_end(int ele)
    {
        Node *n = new Node(ele);
        if (tail == nullptr)
        {
            head = tail = n; // first n is assigned to tail then result is assigned to head
            return;
        }
        tail->next = n;
        tail = n;
        size = 1;
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
        size = 1;
    }
    void pop_front()
    {
        Node *p = head;
        if (head == nullptr)
        {
            cout << "underflow " << endl;
            return;
        }

        head = head->next;
        size--;
        // we are doing this condn coz if we removed 1st element and if there is not element in the list then where tail points to
        if (head == nullptr)
        {
            tail = nullptr;
        }
    }
    void pop_end()
    {
        if (tail == nullptr)
        {
            cout << "underflow " << endl;
            return;
        }
        if (head == tail)
        {
            head = tail = nullptr;
            return;
        }
        Node *p = head;
        while (p->next != tail)
        {
            p = p->next;
        }
        p->next = nullptr;
        tail = p;
        size--;
    }
    void insert(int data, int n)
    {
        Node *temp1 = new Node(data);

        if (n == 1)
        {
            temp1->next = head;
            head = temp1;
            return;
        }

        Node *temp2 = head;
        for (int i = 0; i < n - 2; i++)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }

    int view_last()
    {
        if (tail == nullptr)
        {
            return -1;
        }
        return tail->data;
    }
    int view_front()
    {
        if (head == nullptr)
        {
            return -1;
        }
        return head->data;
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
    void recursivePrint(Node *head)
    {
        //10,20,30,40
        if(head == nullptr) return;
        cout<<head->data;
        recursivePrint(head->next);
    }
    bool searchEle(int ele)
    {
        Node *temp = head;
        while(temp!=nullptr)
        {
            if(temp->data == ele) return true;
        }
        return false;
    }
};
int main()
{
    linkedlist lst;
    lst.push_front(10);
    lst.push_end(20);
    lst.insert(120, 2);
    lst.display_lst();
    // lst.recursivePrint(lst.head); make head public 

    return 0;
}