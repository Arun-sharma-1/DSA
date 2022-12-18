#include <bits/stdc++.h>
using namespace std;
void max_priority_queue()
{
    // PRIORITY QUEUE FOR MAX
    priority_queue<int> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout << pq.size() << endl; //pq.pop(); //pq.empty()
    cout << pq.top() << endl;
}
void program_1()
{
    int arr[]={10,5,14};
    priority_queue<int,vector<int>,greater<int>>pq(arr,arr+3);
    while(pq.size())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main()
{
    // PRIORITY QUEUE FOR MIN
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);
    // cout << pq.size() << endl;
    // cout << pq.top() << endl;
    program_1();
}