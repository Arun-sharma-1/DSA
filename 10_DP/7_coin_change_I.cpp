#include <bits/stdc++.h>
using namespace std;
long long int dp[1002][1002];
long long int solve(int coins[], int N, int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    if (N < 0)
        return 0;

    if (dp[N][sum] != -1)
        return dp[N][sum];
    if (coins[N] <= sum)
    {
        return dp[N][sum] = solve(coins, N, sum - coins[N]) + solve(coins, N - 1, sum);
    }
    else
        return dp[N][sum] = solve(coins, N - 1, sum);

    return dp[N][sum];
}
long long int count(int coins[], int N, int sum)
{

    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    memset(dp, -1, sizeof(dp));
    return solve(coins, N - 1, sum);
}
long long int count(int coins[], int N, int sum)
{

    long long int dp[N + 1][sum + 1];
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][sum];
}
int main()
{
}