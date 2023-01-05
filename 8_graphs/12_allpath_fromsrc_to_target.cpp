#include <bits/stdc++.h>
using namespace std;
void DFS(int src, vector<vector<int>> &adj, vector<vector<int>> &res, vector<int> &path)
{
    path.push_back(src);
    if (src == adj.size() - 1)
    {
        res.push_back(path);
    }
    else
    {
        for (auto v : adj[src])
        {
            DFS(v, adj, res, path);
        }
    }
    path.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> res;
    vector<int> path;
    int src = 0;
    DFS(src, graph, res, path);
    return res;
}
int main()
{
    return 0;
}