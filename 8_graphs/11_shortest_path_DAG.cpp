#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, int M, vector<vector<int>> &edges)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto x : edges)
    {
        int s = x[0];
        int d = x[1];
        int c = x[2];

        adj[s].push_back({d, c});
    }
    int src = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    vector<int> distance(n, 10001);
    distance[src] = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto front = q.front();
            q.pop();
            int u = front.first;
            int d = front.second;

            for (auto v : adj[u])
            {
                int node = v.first;
                int dist = v.second;
                if (distance[node] > dist + d)
                {
                    distance[node] = dist + d;
                    q.push({node, dist + d});
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (distance[i] >= 10001)
        {
            distance[i] = -1;
        }
    }
    return distance;
}
int main()
{
}