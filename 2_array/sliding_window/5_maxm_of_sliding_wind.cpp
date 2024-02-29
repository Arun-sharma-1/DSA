#include <bits/stdc++.h>
using namespace std;
vector<int> max_of_subarrays(int *arr, int n, int k)
{
    vector<int> res;
    list<int> l;

    int i = 0, j = 0;

    // sliding window tech

    while (j < n)
    {
        // calculations
        while (l.size() > 0 && l.back() < arr[j])
        {
            l.pop_back();
        }

        l.push_back(arr[j]);

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {

            res.push_back(l.front());
            // we have to remove some calcuations
            if (l.front() == arr[i])
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return res;
}
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    list<int> q; // or // deque<int>q;
    int i = 0, j = 0;
    int n = nums.size();
    vector<int> res;
    while (j < n)
    {
        while (!q.empty() && q.back() < nums[j])
            q.pop_back();
        q.push_back(nums[j]);
        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            res.push_back(q.front());
            if (q.front() == nums[i])
                q.pop_front();
            i++;
            j++;
        }
    }
    return res;
}
int main()
{
}