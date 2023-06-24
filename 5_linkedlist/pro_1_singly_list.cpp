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
    // void push_end(int ele)
    // {
    //     Node *n = new Node(ele);
    //     if (tail == nullptr)
    //     {
    //         head = tail = n;
    //         return;
    //     }
    //     tail->next = n;
    //     tail = n;
    //     size = 1;
    //     return;
    // }
    // void push_front(int ele)
    // {
    //     Node *n = new Node(ele);
    //     if (head == nullptr)
    //     {
    //         tail = head = n;
    //         return;
    //     }
    //     n->next = head;
    //     head = n;
    //     size = 1;
    // }
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
        // {
            tail = nullptr;
        }
    }
    // void pop_end()
    // {
    //     if (tail == nullptr)
    //     {
    //         cout << "underflow " << endl;
    //         return;
    //     }
    //     if (head == tail)
    //     {
    //         head = tail = nullptr;
    //         return;
    //     }
    //     Node *p = head;
    //     while (p->next != tail)
    //     {
    //         p = p->next;
    //     }
    //     p->next = nullptr;
    //     tail = p;
    //     size--;
    // }
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
        for (int i = 0; i < n - 2; i++) // upto n-2 will givve the exact posn where we want to insert
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }

    // int view_last()
    // {
    //     if (tail == nullptr)
    //     {
    //         return -1;
    //     }
    //     return tail->data;
    // }
    // int view_front()
    // {
    //     if (head == nullptr)
    //     {
    //         return -1;
    //     }
    //     return head->data;
    // }
    // void display_lst()
    // {
    //     Node *p = head;
    //     while (p != nullptr)
    //     {
    //         cout << p->data << " ";
    //         p = p->next;
    //     }
    // }
    // void recursivePrint(Node *head)
    // {
    //     // 10,20,30,40
    //     if (head == nullptr)
    //         return;
    //     cout << head->data;
    //     recursivePrint(head->next);
    // }
    // bool searchEle(int ele)
    // {
    //     Node *temp = head;
    //     while (temp != nullptr)
    //     {
    //         if (temp->data == ele)
    //             return true;
    //     }
    //     return false;
    // }
    // PRINT MIDDLE ELEMENT
    // void printMiddle()
    // {
    //     if (head == nullptr)
    //         return;
    //     Node *curr = head;
    //     int count = 0;
    //     while (curr != nullptr)
    //     {
    //         curr = curr->next;
    //         count++;
    //     }
    //     curr = head;
    //     for (int i = 0; i < count / 2; i++)
    //     {
    //         curr = curr->next;
    //     }
    //     cout << "middle element " << curr->data << endl;
    // }
    // void MiddleElement()
    // {
    //     Node *slow = head;
    //     Node *fast = head;
    //     while (fast != nullptr && fast->next != nullptr) // for even and odd case both
    //     {
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     cout << "middle element is " << slow->data;
    // }
    // void NFromEnd(int n)
    // {
    //     if (head == nullptr)
    //         return;
    //     int count = 0;

    //     for (Node *temp = head; temp != nullptr; temp = temp->next)
    //         count++;
    //     Node *temp = head;
    //     for (int i = 0; i < (count - n); i++)
    //     {
    //         temp = temp->next;
    //     }
    //     cout << "last element from n is " << temp->data;
    // }
    // void printNFromEnd(int n)
    // {
    //     // in this method we don't have to find the length of LL
    //     if (head == nullptr)
    //         return;
    //     Node *first = head;
    //     Node *second = head;
    //     // we move first pointer n times
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (first == nullptr)
    //             return;
    //         first = first->next;
    //     }
    //     // increasing first and second pointer upto last of LL and at the second pointer we are getting our required output
    //     while (first != nullptr)
    //     {
    //         first = first->next;
    //         second = second->next;
    //     }
    //     cout << endl
    //          << "last " << n << " ele " << second->data;
    // }
    // REMOVE DUPLICATES FROM LINKED LIST
    // void removeDuplicate()
    // {
    //     Node *curr = head;
    //     // cout<<curr->next->data<<endl;
    //     while (curr != nullptr && curr->next != nullptr) // both condition is nessacary
    //     {
    //         if (curr->data == curr->next->data)
    //         {
    //             Node *temp = curr->next->next;
    //             curr->next = temp;
    //         }
    //         curr = curr->next;
    //     }
    // }
    Node *reverseLL(Node *head)
    {
        Node *curr = head;
        Node *prev = nullptr;
        while (curr != nullptr)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev; // now this become head
    }
    bool isPalindrome()
    {
        Node *slow = head;
        Node *fast = head;
        // find middle elemnt and reverse it because in signly linked list we don't have point to backward
        // for that we will reverse the linked list from middle to get pointers
        while (fast != nullptr && fast->next != nullptr) // for even and odd case both
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow = middle element  ka address (that we want)
        Node *rev = reverseLL(slow);
        Node *curr = head;
        while (rev != nullptr) // direction is reverse , so will not point after half of the linked list
        {
            if (rev->data != curr->data)
                return false;
            curr = curr->next;
            rev = rev->next;
        }
        return true;
    }
    int intersectionPointLL(Node *n1, Node *n2)
    {
        if (n1 == nullptr || n2 == nullptr)
            return -1;
        Node *temp1 = n1;
        Node *temp2 = n2;
        int count1 = 0, count2 = 0;
        while (temp1 != nullptr)
        {
            count1++;
            temp1 = temp1->next;
        }
        while (temp2 != nullptr)
        {
            count2++;
            temp2 = temp2->next;
        }

        // ABS function doesn't impact the positive numbers but converts negative numbers into positive values
        temp1 = n1;
        temp2 = n2;
        int d = abs(count1 - count2);
        // cout << "value of d " << d << endl;
        for (int i = 0; i < d; i++)
        {
            if (temp1 == nullptr)
                return -1;
            temp1 = temp1->next;
        }
        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->data == temp2->data)
                return temp1->data;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return -1;
    }
    Node *SegregateLL(Node *head)
    {
        Node *oddH = nullptr, *oddT = nullptr, *evenH = nullptr, *evenT = nullptr;
        while (head != nullptr)
        {

            if ((head->data) % 2 == 0)
            {

                // even
                if (evenH == nullptr)
                {
                    // firstTime
                    evenT = evenH = head;
                }
                else
                {
                    evenT->next = head;
                    evenT = evenT->next;
                }
            }
            else
            {
                // odd
                if (oddH == nullptr)
                {
                    oddT = oddH = head;
                }
                else
                {
                    oddT->next = head;
                    oddT = oddT->next;
                }
            }
            head = head->next;
        }
        if (oddH == nullptr)
            return evenH;
        if (evenH == nullptr)
            return oddH;

        evenT->next = nullptr;
        oddT->next = evenH;
        return oddH;
    }
    // bool detectLoop()
    // {
    //     // we use concept of temp node , we will point everynode to that temp node and then check the address
    //     Node *temp = new Node(0);
    //     Node *curr = head;
    //     while (curr != nullptr)
    //     {
    //         //  2.conditons
    //         if (curr->next == nullptr)
    //             return false;
    //         if (curr->next == temp)
    //             return true;
    //         // 1.work to done
    //         Node *currNext = curr->next;
    //         curr->next = temp;
    //         curr = currNext;
    //     }
    //     return false;
    // }

    void lastElementToFirst()
    {
        if (head == nullptr || head->next == nullptr)
            return;
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        // cout<<temp->data<<endl;
        Node *last = temp->next;
        cout << endl
             << temp->data;

        Node *first = head;
        temp->next = nullptr;
        head = last;
        last->next = first;
    }
};
int main()
{
    linkedlist lst;
    lst.push_front(1);
    lst.push_end(2);
    lst.push_end(3);
    lst.push_end(4);

    linkedlist lst2;

    lst2.push_end(20);
    lst2.push_end(30);
    lst2.push_end(40);

    lst.display_lst();
    lst.lastElementToFirst();
    cout << endl;
    lst.display_lst();

    // cout << lst.intersectionPointLL(lst.head, lst2.head);
    // Node *head = lst.SegregateLL(lst.head);
    // while (head != nullptr)
    // {
    //     cout << head->data << ",";
    //     head = head->next;
    // }

    // lst.push_end(50);
    // lst.removeDuplicate();
    // lst.display_lst();
    // cout << endl;
    // cout << lst.isPalindrome();
    // lst.insert(120, 2);
    // lst.recursivePrint(lst.head); make head public
    // cout<<endl;
    // lst.MiddleElement();
    // cout<<endl;
    // lst.printNFromEnd(2);
    // cout<<endl;

    // lst.NFromEnd(2);
    // lst.reverseLL();
    // lst.display_lst();
    // cout << endl
    //      << lst.detectLoop();
    return 0;
}