#include <bits/stdc++.h>
using namespace std;
int equalPartition(int N, int arr[])
{
    long long sum = accumulate(arr, arr + N, 0);
    int target = sum / 2;

    bool dp[N + 1][sum + 1];
    if (sum % 2 != 0)
        return 0;

    else
    {
        // subset sum logic

        // 1.base cond;
        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][target];
}
int main()
{
}