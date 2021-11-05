#include<bits/stdc++.h>
using namespace std;
class Queue
{
    public:
    stack<int>s1,s2;
    // we are using two stacks for implemeting 

    void enqueue(int n) // O(n)
    {
        while(!s1.empty())
        {
            int t=s1.top();
            s2.push(t);
            s1.pop();
        }
        s1.push(n);

        while(!s2.empty())
        {
            int t=s2.top();
            s1.push(t);
            s2.pop();
        }
    }

    int  deque() // O(1)
    {
         if (s1.empty()) 
         {
            cout << "Q is Empty";
            return 0;
        }
        s1.pop();
       
    }
    
    int peek()// O(1)
    {
        int t=s1.top();
        return t;
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(3);
    q.deque();
    cout<<q.peek();
    q.enqueue(2);
    q.deque();
    cout<<" "<<q.peek();


    return 0;
}