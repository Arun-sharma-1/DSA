#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return (a>b)? a: b;
}

int knapsack(vector<int>wt , vector<int>val , int W, int n)
{    
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    // base condition to initilization
        for(int i=0; i<n; i++)
        for(int j=0; j<W; j++)
        {
            if(i==0 || j==0)    dp[i][j]=0;
        }

        for(int i=1; i<n+1; i++)
        for(int j=1; j<W+1; j++)
        {
            if(wt[i-1]<= j)    dp[i][j]= max(val[i - 1] + dp[i - 1] [j - wt[i - 1]], dp[i - 1][j]);
            else  dp[i][j]= dp[i-1][j];
        }
        
        return dp[n][W];
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

     // for( i=1; i<n+1; i++)
    // {
    //     for(j=1; j<W+1; j++)
    //     {
    //         if(wt[i-1]<= j)
    //         {
    //             dp[i][j]= max(val[i - 1] +
    //                             dp[i - 1] [W - wt[i - 1]],
    //                             dp[i - 1][j]);
    //             // return dp[i][j];
    //         }
    //         else 
    //         {
    //             dp[i][j]= dp[i-1][j];
    //             // return  dp[i][j];
    //         }  

    //     }
    // }
    // return dp[i][j];
    