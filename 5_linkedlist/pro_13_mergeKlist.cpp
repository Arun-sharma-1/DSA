#include <bits/stdc++.h>
using namespace std;
Node *mergeKLists(Node *arr[], int K)
{
    priority_queue<Node *, vector<Node *>, mycmp> pq;
    for (int i = 0; i < K; i++)
    {
        if (arr[i])
            pq.push(arr[i]);
    }
    Node *head = nullptr;
    Node *tail = nullptr;

    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        if (head == nullptr)
        {
            head = tail = x;
        }
        else
        {
            tail->next = x;
            tail = x;
        }
        if (x->next)
            pq.push(x->next);
    }
    return head;
}
int main()
{
}