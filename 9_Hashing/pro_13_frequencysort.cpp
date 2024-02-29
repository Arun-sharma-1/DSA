#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
class compare
{
public:
    bool operator()(pi p1, pi p2)
    {
        if (p1.first == p2.first)
        {
            return p1.second < p2.second;
        }
        else
            return p1.first > p2.first;
    }
};
vector<int> frequencySort(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    priority_queue<pi, vector<pi>, compare> pq; // freq , value 
    vector<int> ans;
    for (auto ele : nums)
    {
        mp[ele]++;
    }
    for (auto &pr : mp)
    {
        int value = pr.first;
        int freq = pr.second;

        pq.push({freq, value});
    }
    while (pq.size())
    {
        int freq = pq.top().first;
        for (int i = 0; i < freq; i++)
        {
            ans.push_back(pq.top().second);
        }
        pq.pop();
    }
    return ans;
}
int main()
{
    return 0;
}