#include <bits/stdc++.h>
using namespace std;
int cutRod(int price[], int n)
{
    int dp[n + 1][n + 1];
    //   vector<vector<int>> dp( n+1 , vector<int> (n+1, 0));
    vector<int> len(n);
    for (int i = 0; i < n; i++)
    {
        len[i] = i + 1;
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    int res = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (len[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - len[i - 1]]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][n];
}
int main()
{
}