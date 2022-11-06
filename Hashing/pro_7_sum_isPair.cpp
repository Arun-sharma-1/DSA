#include <bits/stdc++.h>
using namespace std;
bool isPair(int a[], int n, int sum)
{
    unordered_set<int> uset;
    int res =0;
    for (int i = 0; i < n; i++)
    {
        if (uset.find(sum - a[i]) != uset.end())
            return true;
        else
            uset.insert(a[i]);
    }
    return false;
}

int main()
{
    int a[] ={8,3,4,2,5};
    int sum =5;
    int n = sizeof(a)/sizeof(a[0]);

    cout<<isPair(a,n,sum);
    return 0;
}