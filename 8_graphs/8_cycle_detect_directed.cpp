#include <bits/stdc++.h>
using namespace std;
bool checkCycle(int s, vector<bool> &visited, vector<bool> &currVisited, vector<int> adj[])
{
    visited[s] = true;
    currVisited[s] = true;

    for (auto child : adj[s])
    {
        if (visited[child] == false)
        {
            if (checkCycle(child, visited, currVisited, adj))
                return true;
        }
        else if (visited[child] == true && currVisited[child] == true)
        {
            return true;
        }
    }
    currVisited[s] = false;

    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> visited(V, false);
    vector<bool> currVisited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            if (checkCycle(i, visited, currVisited, adj))
                return true;
        }
    }
    return false;
}
int main()
{
    /*
    Cycle detection in directed graph can be done using BFS also , for that we use topological sorting 
    Topological sorting is only done with directed acyclic graph if we visit all the nodes then 
    topological sorting can be done so we can keep count==N then top sorting done otherwise return false
    */
}