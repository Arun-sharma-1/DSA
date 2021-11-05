#include<bits/stdc++.h>
using namespace std;

#define INF 99999
void bellman(int src, vector<vector<int>>&edges, vector<int>&dist )
{
    dist[src]=0;

    for(int i=0; i<dist.size()-1 ; i++)
    {
        for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            if(dist[u]+ w < dist[v])
            {

                dist[v]=dist[u]+w; 
                
            }
        }
    }
     for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];

            if(dist[u]+ w < dist[v])
            {
                cout<<"negative cycle detected ";
                 return ;
            }
        }
 
}
  
int main()
{
    vector<vector<int>>edges={{0,1,4},{0,7,8},{1,2,8},{1,7,11},{2,3,7},{2,5,4},{2,8,2},{3,4,9},{3,5,14},{4,5,10},{5,6,2},{6,7,1},{6,8,6},{7,8,7}};
    vector<int>dist(9,INF);
    
    bellman(0,edges,dist);
    return 0;
    
    for(int i=0; i<9; i++)
        {
            cout<<i<<" "<<dist[i]<<endl;
        }

//   #include<bits/stdc++.h>
//  using namespace std;
//  int main()
//  {
//       vector<vector<int>>edges={{0,1,4},{0,7,8},{1,2,8},{1,7,11},{2,3,7},{2,5,4},{2,8,2},{3,4,9},{3,5,14},{4,5,10},{5,6,2},{6,7,1},{6,8,6},{7,8,7}};
//         for(auto edge: edges )
//         {
//             cout<<edge[2];
            
            
//         }
     
//  }