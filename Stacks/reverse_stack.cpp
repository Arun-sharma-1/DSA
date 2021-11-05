#include<bits/stdc++.h>
using namespace std;
void insert_bottom(stack<int>&s, int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }

    int temp=s.top();
    s.pop();

    insert_bottom(s,ele);
    s.push(temp);
}
void reverse(stack<int>&s)
{
    if(s.empty())
    {
        return;
    }

    int temp=s.top();   // temp=10
    s.pop(); // stack empty 
    reverse(s);
     
    insert_bottom(s,temp);
    return;
}
int main()
{
      stack<int>s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);

       reverse(s);
        while (!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        


}