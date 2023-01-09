#include <bits/stdc++.h>
using namespace std;
// using priority queue
// kth largest element
int findKthLargest(vector<int> &nums, int k)
{
    // hello world soln
    // for finding largest we have to create min heap and for finding smallest we have create max heap
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (auto ele : nums)
    {
        pq.push(ele);
        // when size become more than k then push one ele
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (auto ele : nums)
        pq.push(ele);
    int top = 0;
    while (k--)
    {
        top = pq.top();
        pq.pop();
    }
    return top;
}
int int main()
{
    int arr[6] = {2, 12, 4, 0, 8, 10};
    // 0,2,4,8,10,12
    int k;
    cin >> k;
    int n = sizeof(arr) / sizeof(arr[0]);
    // sort(arr, arr + n);

    // for(int i=0; i<n; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<arr[k-1];

    cout << maxiEle(arr, n, k);
}
