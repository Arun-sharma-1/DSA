#include <bits/stdc++.h>
using namespace std;
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
int kthLargestSumContigousSubarray(vector<int> &Arr, int N, int k)
{
    // when you have to find largest then create min heap and when you hvae to find smallest use max hep
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += Arr[j];

            pq.push(sum);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
}
int main()
{
    return 0;
}