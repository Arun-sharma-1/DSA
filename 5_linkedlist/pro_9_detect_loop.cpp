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
void insertAtTail(Node *&head, int ele)
{
    Node *n = new Node(ele);
    if (head == nullptr)
    {
        n->next = n;
        head = n;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void display(Node *head)
{
    if (head == nullptr)
        return;
    cout << head->data << " ";
    for (Node *p = head->next; p != head; p = p->next)
    {
        cout << p->data << " ";
    }
}

/*

bool detectLoop(Node *head)
{
    // flyood warshall algorithm
    // we use concept of slow and fast pointer if they come on same element then list contain cycle
    Node *slow = head, *fast = head;
    while (fast->next != nullptr && fast != nullptr) // both conditon are nessasary if using fast and slow pntr
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
     return false;
}

bool detectLoop(Node *head)
{
    // we use concept of temp node , we will point everynode to that temp node and then check the address
    // in this method we destroy the link
    Node *temp = new Node(0);
    Node *curr = head;
    while (curr != nullptr)
    {
        //  2.conditons
        if(curr->next == nullptr) return false;
        if(curr->next == temp) return true;
        // 1.work to done
        Node *currNext = curr->next;
        curr->next = temp;
        curr = currNext;
    }
    return false;
}
*/
bool detectLoop(Node *head)
{
    // using unordered_set , we store the address
    unordered_set<Node *> s;
    for (Node *p = head; p != nullptr; p = p->next)
    {
        if (s.find(p) != s.end())
            return true;
        s.insert(p);
    }
    return false;
}
void detectRemoveLoop(Node *head)
{
    if (head == nullptr)
        return;
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }
    slow = head;
    while (slow->next != fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next = nullptr;
    return;
}
int main()
{
    Node *head = nullptr;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    // display(head);
    cout << detectLoop(head)<<endl;;
    detectRemoveLoop(head);
    cout << detectLoop(head);

    return 0;
}