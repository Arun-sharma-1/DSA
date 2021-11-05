#include<bits/stdc++.h>
using namespace std;
int main()
{
     string s="leetcode";
     unordered_map<char,int>umap;
     for(auto ele: s)
       {
            umap[ele]++;
       }
       
      for(auto ele : umap)
      {
           cout<<ele.first<<" "<<ele.second<<endl;
      }
}