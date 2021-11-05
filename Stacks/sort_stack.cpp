
#include<bits/stdc++.h>
using namespace std;
void sort(stack<int>&s)
{
    int ele=s.top(); // 50
    s.pop();
    while(!s.empty())
    {
        if(ele < s.top())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
}
int main()
{
      stack<int>s;
         s.push(50);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);

        sort(s);
        


}