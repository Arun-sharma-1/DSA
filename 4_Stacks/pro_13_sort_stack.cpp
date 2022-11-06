#include <bits/stdc++.h>
using namespace std;
void insertAtRightPosn(stack<int> &s, int ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }
    int temp = s.top();
    if (temp < ele)
    {
        s.pop();
        insertAtRightPosn(s, ele);
    }
    else
    {
        s.push(ele);
        return;
    }
    s.push(temp);
}
void sortStack(stack<int> &s)
{
    if (s.empty())
        return;
    int temp = s.top();
    s.pop();
    sortStack(s);
    insertAtRightPosn(s, temp);
    return;
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(15);
    s.push(5);
    s.push(30);
    sortStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}