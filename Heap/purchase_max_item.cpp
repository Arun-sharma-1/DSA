#include <bits/stdc++.h>
using namespace std;
int main()
{
    // maxitem sum=10
    int arr[] = {1, 12, 5, 111, 220};
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + 5);
    int maxm = 0, res = 0;
    int sum = 10;
    while (!pq.empty())
    {
        maxm += pq.top();
        
        if (maxm <= sum)
            res++;

        pq.pop();
    }
    cout << res;
}