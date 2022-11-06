#include <bits/stdc++.h>
using namespace std;
int intersection(int a[], int b[], int n, int m)
{
    unordered_set<int> uset(a, a + n);
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        if (uset.find(b[i]) != uset.end())
        {
            res++;
            uset.erase(b[i]);
        }
    }
    return res;
}
int main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    cout << intersection(a, b, n, m);
    return 0;
}