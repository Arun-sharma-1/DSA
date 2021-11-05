#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(vector<int>wt, vector<int> val , int W ,int n)
{ 
    vector<vector<int>>dp(wt.size()+1, vector<int>(W+1,-1)); // memoization

      if(W==0 || n ==0 ) return 0; // base condn
      if(dp[n][W] !=-1) return dp[n][W];
      if(W >= wt[n-1])
      {
          dp[n][W]=max(val[n-1] + knapsack(wt,val,W-wt[n-1], n-1), knapsack(wt,val, W, n-1));
          return  dp[n][W];
      }

      else if(wt[n-1] > W) 
      { 
        dp[n][W]= knapsack(wt,val,W,n -1);
        return dp[n][W];
      }  
} 
int main()
{   
    vector<int>wt={1,2,4,5};
    vector<int>val={1,4,5,7 };
     
    int W = 7;
    int n = wt.size();
     
   
    cout << knapsack(wt,val,W,n);
    return 0;
} 



// #include<bits/stdc++.h>
// using namespace std;
// int max(int a,int b)
// {
//     return (a>b)? a:b;
// }
// int knapsack(vector<int>wt,vector<int>val,int W,int n)
// {
     
//     if(n==0 || W==0 ) return 0; // base condition
    
//     if(wt[n-1]<=W) 
//     return max(val[n-1] + knapsack(wt,val,W-wt[n-1] , n-1) , knapsack(wt,val,W,n-1));
    
//     else
//     return knapsack(wt,val,W,n-1);
// }
// int main()
// {
//     vector<int>wt{1,2,,5,7};
//     vector<int>val{10,4,5,7};
//     int W=7; // maxm weight
//     int n=val.size();
//     cout<< knapsack(wt,val,W , n);
// }