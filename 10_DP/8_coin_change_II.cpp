#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    int N = coins.size();
    int dp[N + 1][amount + 1];

    // base condn
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            if (i == 0)
                dp[i][j] = INT_MAX - 1;
            if (j == 0)
                dp[i][j] = 0;
        }
    }

    // for(int j=1; j<=amount; j++)
    // {
    //     if(j%coins[0] == 0)
    //     {
    //         dp[1][j] = j/coins[0];
    //     }
    //     else dp[1][j] = INT_MAX - 1;
    // }
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < amount + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    if (dp[N][amount] == INT_MAX - 1)
        return -1;
    return dp[N][amount];
}
int main()
{
}