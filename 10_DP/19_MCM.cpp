#include <bits/stdc++.h>
using namespace std;
int dp[102][102];
int solve(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int mini = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (mini > temp)
            mini = temp;
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(int N, int arr[])
{
    // code here
    memset(dp, -1, sizeof(dp));
    return solve(arr, 1, N - 1);
}
int main()
{
    return 0;
}