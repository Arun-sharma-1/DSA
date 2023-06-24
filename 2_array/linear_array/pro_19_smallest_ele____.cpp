#include<bits/stdc++.h>
using namespace std;
// how many elements are smaller than the curr element in array
//leetcode problem
void getSmallest(int arr[], int n)
{
    vector<int>v;
    sort(arr,arr+n);
    unordered_map<int,int>umap;
    for(int i=0; i<n; i++) umap.insert({arr[i] , i}); // this insert function is wrong we have to push index of element not just i
    for(auto i = umap.begin(); i!=umap.end(); i++)
    {
        v.push_back(i->second);
    }
    for(auto ele: v) cout<<ele<<" ";
}
int main()
{
    int arr[]={8,1,2,2,3}; // 4 0 1 1 3
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sort(arr,arr+n,greater<int>());
    getSmallest(arr,n);
    return 0;
}