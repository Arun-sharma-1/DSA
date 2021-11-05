#include<bits/stdc++.h>
using namespace std;
int fibo(int n, unordered_map<int,int> &dp)
{
    if(n==1 || n==2 ) return 1;
    if(dp.find(n)==dp.end())
    {
        dp[n]=fibo(n-1,dp) + fibo(n-2,dp);

    }
    return dp[n];
}
int main()
{
    unordered_map<int,int>dp;

    int n;
    cin>>n;

    cout<<fibo(n,dp);
}