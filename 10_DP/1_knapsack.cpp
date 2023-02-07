#include <bits/stdc++.h>
using namespace std;
// RECURSION + STORAGE = MEMOIZATION

int solve(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (dp[W][n] != -1)
        return dp[W][n];
    if (W >= wt[n - 1])
    {
        return dp[W][n] = max(val[n - 1] + solve(W - wt[n - 1], wt, val, n - 1), solve(W, wt, val, n - 1));
    }
    else
        return dp[W][n] = solve(W, wt, val, n - 1);
}
int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    memset(dp, -1, sizeof(dp));
    return solve(W, wt, val, n);
}

// ITERATIVE
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0; // this is  just base condition of recursion
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
int main()
{
}