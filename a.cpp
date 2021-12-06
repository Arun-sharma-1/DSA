#include <bits/stdc++.h>
using namespace std;
void DFS(int src, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj)
{
    cout << src << " ";
    visited[src] = true;

    for (auto child : adj[src])
    {
        if (!visited[child])
        {
            DFS(child, visited, adj);
        }
    }
}
void BFS(unordered_map<int, bool>visited, unordered_map<int, vector<int>> &adj)
{
    queue<int> nodes;
    nodes.push(1);
    visited[1] = true;

    while (!nodes.empty())
    {
        int curr = nodes.front();
        cout << curr << " ";
        nodes.pop();

        for (auto child : adj[curr])
        {
            if (!visited[child])
            {
                nodes.push(child);
                visited[child] = true;
            }
        }
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
    // DFS(1, visited, adj);
    // cout << endl;
    BFS(visited,adj);
    return 0;
}