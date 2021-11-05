#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>>Tree;
    int edge,n1,n2;
    cout<<"Enter edge ";
    cin>>edge;

    Tree.resize(edge);

  for(int i=0; i<edge; ++i)
  {
      cin>>n1>>n2;
      Tree[n1].push_back(n2);
  }

  for(const auto &ele:Tree)
  {
      for(const auto &e2:ele)
      {
          cout<<e2;
      }
      cout<<endl;
  }
}