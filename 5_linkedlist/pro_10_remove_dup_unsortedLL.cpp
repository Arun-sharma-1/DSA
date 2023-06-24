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
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        unordered_set<int> uset;
        Node *curr = head;
        // we are inserting first element and according to that element comparing other elements
        // first ele will not be duplicate
        if (curr != nullptr)
        {
            uset.insert(curr->data);
        }
        else
            return head;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (uset.find(curr->next->data) != uset.end())
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
                uset.insert(curr->data);
            }
        }
        return head;
    }
    Node *removeDuplicates(Node *head)
    {
        unordered_map<int, bool> mp;
        Node *curr = head;
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            if (mp[curr->data] == true)
            {
                prev->next = curr->next;
                delete (curr);
                curr = prev->next;
            }
            else
            {
                mp[curr->data] = true;
                prev = curr;
                curr = curr->next;
            }
        }
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

    lst.display_lst();
}