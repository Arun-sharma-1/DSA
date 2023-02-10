#include <bit/stdc++.h>
using namespace std;
// RECURSIVE
bool solve(vector<int> arr, int n, int sum, int dp[][1000])
{
    // base condn
    if (sum == 0)
        return true;
    if (n == 0) // abb sum 0 nhi h => elements nhi h , or sum> 0 return false
        return false;

    if (dp[n][sum] != -1)
        return dp[n][sum];
    // choice diagram
    if (arr[n - 1] <= sum)
    {
        // choice => select kru ya nhi

        return dp[n][sum] = solve(arr, n - 1, sum - arr[n - 1], dp) || solve(arr, n - 1, sum, dp);
    }
    else
        return dp[n][sum] = solve(arr, n - 1, sum, dp);
}

bool isSubsetSum(vector<int> arr, int sum)
{

    int n = arr.size();
    int dp[110][1000];
    memset(dp, -1, sizeof(dp));
    return solve(arr, n, sum, dp);
}

// ITERATIVE
bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    bool dp[n + 1][sum + 1];

    // base condition
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0 & j == 0)
                dp[i][j] = true;
            if (i == 0)
            {
                dp[i][j] = false;
            }
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                // dp[i][j] = max(dp[i - 1][j - arr[i - 1]], dp[i - 1][j]);
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    // array diya h , or sum diya h = > elements ko select kr k sum ban skta h kya
}