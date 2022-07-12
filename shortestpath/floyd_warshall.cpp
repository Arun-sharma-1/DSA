#include<bits/stdc++.h>
using namespace std;

#define INF 99999
 void floyd_washell(vector<vector<int>>& adjmatrix)
 {
     int n=adjmatrix.size();
     for(int k=0; k<n; k++)
     {
         for(int i=0; i<n; i++)
         {
             for(int j=0; j<n; j++)
             {
                 if(adjmatrix[i][k] + adjmatrix[k][j] < adjmatrix[i][j])
                 {
                      adjmatrix[i][j]=adjmatrix[i][k] + adjmatrix[k][j];
                 }
             }
         }
     }
 }
  
int main()
{
    vector<vector<int>>edges={
                                {0,5,INF,10},
                                {INF, 0,3,INF},
                                {INF,INF,0,1},
                                {INF,INF,INF,0}
                             };
    // vector<int>dist(9,INF);

    floyd_washell(edges);
    for(auto edge : edges)
    {
        cout<<edge[0]<<" "<<edge[1]<<" "<<edge[2]<<endl;
    }
    
    

}

 