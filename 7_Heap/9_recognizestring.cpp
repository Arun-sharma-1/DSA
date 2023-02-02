#include <bits/stdc++.h>
using namespace std;
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
string reorganizeString(string s)
{
    unordered_map<char, int> um;
    for (auto ele : s)
    {
        um[ele]++;
    }
    priority_queue<pair<int, char>> pq;

    for (auto ele : um)
    {
        pq.push({ele.second, ele.first});
    }
    string ans = "";
    pair<int, char> block = {-1, '&'};
    while (pq.size() > 0)
    {
        auto top = pq.top();
        pq.pop();
        ans += top.second;
        top.first--;

        if (block.first > 0)
            pq.push(block);
        block = top;
    }
    if (ans.length() == s.length())
        return ans;
    return "";
}
int main()
{
}