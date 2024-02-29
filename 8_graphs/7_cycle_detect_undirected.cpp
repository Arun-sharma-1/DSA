#include <bits/stdc++.h>
using namespace std;

// Cycle detection in undirected use concept of parent and child for checking the loops in both dfs and bfs

// CYCLE DETECTION USING DFS
bool detectCycle(int src, vector<int> adj[], unordered_map<int, bool> &visited, int parent)
{
    visited[src] = true;
    for (auto child : adj[src])
    {
        if (visited[child] == false)
        {
            if (detectCycle(child, adj, visited, src) == true)
                return true;
        }
        else if (child != parent)
        {
            return true;
        }
    }
    return false;
}
// CYCLE DETECTION USING BFS

bool checkCycleBFS(int s, vector<bool> &visited, vector<int> adj[])
{
    queue<pair<int, int>> q; // node and parent
    q.push({s, -1});
    visited[s] = true;

    while (!q.empty())
    {
        auto u = q.front();
        int source = u.first;
        int parent = u.second;

        q.pop();
        for (int v : adj[source])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push({v, source});
            }
            else if (v != parent)
                return true;
        }
    }
    return false;
}
bool isCycle(int v, vector<int> adj[])
{
    // Code here
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            if (detectCycle(i, adj, visited, -1))
                return true;
    }
    return false;
}
int main()
{
}

/* 
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool detectCycle(int s, vector<int> adj[], vector<int> &visited, int parent)
    {
        visited[s] = true;

        for (auto child : adj[s])
        {
            if (child == parent)
                continue;
            if (visited[child] == true && child != parent)
                return true;

            if (detectCycle(child, adj, visited, s))
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if (detectCycle(i, adj, visited, -1))
                    return true;
        }
        return false;
    }
};







//USING BFS
class Solution {
  public:
    bool checkCycle(int s, vector<int>adj[] ,vector<int>&visited)
    {
        queue<pair<int,int>>q;
        q.push({s,-1});
        visited[s] = true;
        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            int value = curr.first;
            int parent = curr.second;
            q.pop();
            for(auto v : adj[value])
            {
                if(v == parent ) continue;
                else if(v!=parent && visited[v]) return true;

                visited[v] = true;
                q.push({v,value});
                
                
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<int>visited(V, false);
        
         for(int i = 0; i<V; i++)
         {
             if(!visited[i])
             {
                 if(checkCycle(i , adj , visited)) return true;
             }
         }
         return false;
    }
};
*/