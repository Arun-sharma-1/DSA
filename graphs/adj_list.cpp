#include <bits/stdc++.h>
using namespace std;
#define v 5

void addEdge(vector<int> adj[v], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; ++i)
    {
        cout << "\n Vertex " << i << ":";
        for (auto ele : adj[i])
            cout << "-> " << ele;
        cout << endl;
    }
}
int main()
{
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 1);

    printGraph(adj, v);
}