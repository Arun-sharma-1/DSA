#include<bits/stdc++.h>
using namespace std;
void reverse(queue<int>&q)
{
    //iterative 
    stack<int>s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
void recursiveReverser(queue<int>&q)
{
    if(q.empty()) return;
    int x = q.front();
    q.pop();

    recursiveReverser(q);
    q.push(x);
}
int main()
{
    queue<int>q;
    for(int i=1; i<6; i++)
    {
        q.push(i);
    }
    recursiveReverser(q);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}