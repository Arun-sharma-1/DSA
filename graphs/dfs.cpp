#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,vector<int>>&adj)
{
    cout<<node<<" ";
    visited[node]=true;
    for(int child: adj[node])
    {
        if(!visited[child])
        {
            dfs(child,visited,adj);
        }
    }
}

void bfs(unordered_map<int,vector<int>>&adj)
{
    queue<int>nodes;
    unordered_map<int,bool>visited;
    nodes.push(1);
    visited[1]=true;

    while(!nodes.empty())
    {
        int curr=nodes.front();
        nodes.pop();
        cout<<curr<<" ";
        
        for(int child: adj[curr])
        {
            if(!visited[child])
            {
                nodes.push(child);
                visited[child]=true;
            }
        }
    }
}  




int main()
{
    //FOLLOWING ADJECNCY LIST 
     vector<vector<int>>edges= {{1,2},{1,5},{2,3},{2,6},{3,4},{3,5},{5,6}};
     unordered_map<int,bool>visited;
     unordered_map<int,vector<int>>adj;

     for(vector<int>ele : edges)
     {
         adj[ele[0]].push_back(ele[1]);
         adj[ele[1]].push_back(ele[0]);
     }

     dfs(1,visited,adj);
     cout<<endl;
     bfs(adj);
}