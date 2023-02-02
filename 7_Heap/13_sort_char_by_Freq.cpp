#include <bits/stdc++.h>
using namespace std;
//LEETCODE 451
string frequencySort(string s)
{
    unordered_map<char, int> mp;
    for (auto x : s)
        mp[x]++;
    priority_queue<pair<int, char>> pq;
    for (auto pr : mp)
    {
        pq.push({pr.second, pr.first});
    }
    string res = "";
    while (pq.size() > 0)
    {
        auto top = pq.top();
        for (int i = 0; i < top.first; i++)
            res += top.second;
        pq.pop();
    }
    return res;
}
int main()
{
}