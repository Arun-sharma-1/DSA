#include <bits/stdc++.h>
bool biPartiteDFS(int u, vector<vector<int>> &graph, vector<int> &color, int currColor)
{
    color[u] = currColor;

    for (auto v : graph[u])
    {
        if (color[v] == color[u])
            return false;
        else if (color[v] != -1)
            continue;
        else if (color[v] == -1)
        {
            int newColor = 1 - currColor;
            if (biPartiteDFS(v, graph, color, newColor) == false)
                return false;
        }
    }
    return true;
}
bool biPartiteBFS(int s, vector<vector<int>> &graph, vector<int> &color, int currColor)
{
    queue<int> q;
    q.push(s);
    color[s] = currColor;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : graph[u])
        {
            if (color[u] == color[v])
                return false;
            else if (color[v] != -1)
                continue;
            else if (color[v] == -1)
            {
                color[v] = 1 - color[u];

                q.push(v);
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (biPartiteBFS(i, graph, color, 1) == false)
                return false;
        }
    }
    return true;
}
using namespace std;
int main()
{
    return 0;
}