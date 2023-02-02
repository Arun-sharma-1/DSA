#include <bits/stdc++.h>
using namespace std;
int getPairCount(int a[], int n, int sum)
{
    unordered_map<int, int> umap;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int b = sum - a[i];
        if (umap[b])
        {
            res += umap[b];
        }
        umap[a[i]]++;
    }
    return res;
}
int main()
{   int arr[] = {1, 5, 7, 1};
    int sum  =2;
    int n =sizeof(arr)/sizeof(arr[0]);

    cout<<getPairCount(arr,4,6);
    return 0;
}