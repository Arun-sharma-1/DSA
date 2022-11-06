#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="arunsharma";
    unordered_map<char,int>umap;

    for(auto ele: s)
    {
        umap[ele]++;
    }

    //items will be present in random order and in case of vector they are in alphabetic order
    for(auto &pr: umap)
    {
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}