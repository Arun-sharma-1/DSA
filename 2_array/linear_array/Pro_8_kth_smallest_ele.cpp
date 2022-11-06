#include<bits/stdc++.h>
using namespace std;
//using priority queue 
//kth largest element 
int maxiEle(int arr[] ,int n ,int k)
{
    //min heap 
    priority_   queue<int,vector<int>,greater<int>>p;
    for(int i=0; i<n; i++)
    {
        p.push(arr[i]);
    }
    int ans = -1, i = 1;
    while(!p.empty())
    {
        if(i == k)
        {
            ans = p.top();
            break;
        }
        i++;
        p.pop();
    }
    return ans;
}
int main()
{
    int arr[6]={2,12,4,0,8,10};
    //0,2,4,8,10,12
    int k;
    cin>>k;
    int n = sizeof(arr) / sizeof(arr[0]);
    // sort(arr, arr + n);
    
    // for(int i=0; i<n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<arr[k-1];

    cout<<maxiEle(arr,n,k);

}
