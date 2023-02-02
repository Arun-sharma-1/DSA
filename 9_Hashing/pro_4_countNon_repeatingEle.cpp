#include <bits/stdc++.h>
using namespace std;
int countDistinctEle(int arr[], int n)
{
    int count = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        umap[arr[i]]++;
    }
    for (auto ele : umap)
    {
        auto item = ele;
        if (item.second == 1)
            cout << ele.first << " " << ele.second << endl;
    }
    return count;
}
int DistinctEle(int arr[], int n)
{
    unordered_set<int> uset(arr, arr + n);
    return uset.size();
}
int main()
{
    int arr[] = {10, 10, 20, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout<<DistinctEle(arr,n);
    countDistinctEle(arr, n);
    return 0;
}