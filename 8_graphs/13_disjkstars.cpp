#include<bits/stdc++.h>
using namespace std;
void dijkstras(int s , unordered_map<int,vector<pair<int,int>>>&adj , unordered_map<int,int>&dist  )
{
    //dist ko update krna
    dist[s] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>>pq; // dis , src
    pq.push({0,s});
    while(!pq.empty())
    {
        pair<int,int> top = pq.top();
        pq.pop();
        int dis = top.first; // 0
        int node = top.second;//0 
        for(auto v : adj[node])
        {
          if(dist[v.first]  > dist[node] + v.second)
          {
              dist[v.first] = dist[node] + v.second;
              pq.push({dist[v.first] , v.first});
          }
        }
    }
}
int main()
{
    vector<vector<int>>edges={{0,1,4},{0,7,8},{1,2,8},{1,7,11},{2,3,7},{2,5,4},{2,8,2},{3,4,9},{3,5,14},{4,5,10},{5,6,2},{6,7,1},{6,8,6},{7,8,7}};
    int n = edges.size();
    unordered_map<int,int>dist;
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto edge: edges)
    {
        dist[edge[0]] = INT_MAX;
        dist[edge[1]] = INT_MAX;
        adj[edge[0]].push_back({edge[1] , edge[2]});
        adj[edge[1]].push_back({edge[0] , edge[2]});
        
    }
    dist[0] = 0;
    dijkstras(0 , adj , dist );
    
    for(auto ele : dist)
    {
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    
}