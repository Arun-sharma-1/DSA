#include <bits/stdc++.h>
using namespace std;
void Shortest_path(int src, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj)
{
    queue<int> nodes;
    nodes.push(src);

    vector<int> result(7, 0);
    result[src] = 0;
    visited[src] = true;

    while (!nodes.empty())
    {
        int curr = nodes.front();
        nodes.pop();

        for (auto child : adj[curr])
        {
            if (!visited[child])
            {
                result[child] = result[curr] + 1;
                nodes.push(child);
                visited[child] = true;
            }
        }
    }

    for (int ele = src; ele < result.size(); ele++)
    {
        cout << result[ele] << " ";
    }
}
int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 5}, {2, 3}, {2, 6}, {3, 4}, {3, 5}, {5, 6}};
    unordered_map<int, bool> visited;
    unordered_map<int, vector<int>> adj;
    for (vector<int> edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    Shortest_path(1, visited, adj);
}