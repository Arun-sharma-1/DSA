#include <bits/stdc++.h>
using namespace std;
vector<int> topSort(int V, vector<int> adj[])
{
    // code here
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        // vector<int> temp = adj[i];
        // for (int i = 0; i < temp.size(); i++)
        // {
        //     indegree[temp[i]]++;
        // }

        for (auto ele : adj[i])
        {
            indegree[ele]++;
        }
    }
    vector<int> res;
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        res.push_back(u);

        for (auto v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    return res;
}

// WITH DFS
void DFS(int s, vector<int> adj[], vector<int> &visited, stack<int> &stk)
{
    if (visited[s] == true)
        return;
    visited[s] = true;
    for (auto v : adj[s])
    {
        if (!visited[v])
        {
            DFS(v, adj, visited, stk);
        }
    }
    stk.push(s);
}

vector<int> topoSort(int v, vector<int> adj[])
{
    // code here
    vector<int> visited(v);
    stack<int> stk;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            // loop is very important in this case it will traverse the non reachable node
            DFS(i, adj, visited, stk);
        }
    }
    vector<int> res;
    while (!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}