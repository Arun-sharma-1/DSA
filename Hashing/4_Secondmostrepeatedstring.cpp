#include <bits/stdc++.h>
using namespace std;
string secFrequent (string arr[], int n)
    {
        unordered_map<string,int>umap;
        
        for(int i=0; i<n; i++)
        {
            umap[arr[i]]++;
        }
        
        int max=0;
        string res;

        //first frequent
        for(auto ele: umap)
        {
            if(ele.second > max)
            {
                max=ele.second;
                res=ele.first;
            }
        }
        //second frequent
        umap[res]=0;
        max=0;
        for(auto ele: umap)
        {
            if(ele.second > max)
            {
                max=ele.second;
                res=ele.first;
            }
        }
        return res;
        
}

int firstRepeated(int *arr, int n) 
{
    unordered_map<int,int>umap;
    for(int i=0; i<n; i++)
        umap[arr[i]]++;
    for(int i=0; i<n; i++)
    {
        int key=arr[i];
        auto temp = umap.find(key);
        if(temp->second >1)
            return i+1;
    }
    return -1;
}
int main()
{
    int a[] = {1, 5, 3, 4, 3, 5, 6};
    // cout<<firstRepeated(a,7);
    
    return 0;
}