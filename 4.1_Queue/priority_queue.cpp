// cost of insertion and extraction is logn
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // min-heap
    priority_queue<int , vector<int> , greater<int>>pq;
    pq.push(30);
    pq.push(20);
    pq.push(10);

    // for(auto ele:{1,21,3,4} )
    // pq.push(ele);

    vector<int>ele={1,21,3,4};
    for(auto i :ele )
    pq.push(i);
    


    while (!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }

    cout<<endl;

    //max heap
    priority_queue<int>q;
    q.push(0);
    q.push(2);
    q.push(10);

    while (!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }

    

    
}