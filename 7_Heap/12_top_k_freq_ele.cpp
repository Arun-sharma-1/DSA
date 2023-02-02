#include <bits/stdc++.h>
using namespace std;
vector<int> topK(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (auto ele : nums)
    {
        mp[ele]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto pr : mp)
    {
        pq.push({pr.second, pr.first});
    }
    vector<int> res;
    while (pq.size() > 0 && k--)
    {
        auto top = pq.top();
        pq.pop();
        res.push_back(top.second);
    }
    return res;
}
int main()
{
}