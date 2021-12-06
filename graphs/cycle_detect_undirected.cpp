#include <bits/stdc++.h>
using namespace std;
bool Cycle_present(int src, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adj, int parent)
{
    visited[src] = true;

    for (auto child : adj[src])
    {
        if (child != parent)
        {
            if (visited[child])
                return true;
            if (!visited[child] && Cycle_present(child, visited, adj, src))
                return true;
        }
    }
    return false;
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
    if (Cycle_present(1, visited, adj, -1))
        cout << "Cycle is present " << endl;
    else
        cout << "Cycle is not present ";
}