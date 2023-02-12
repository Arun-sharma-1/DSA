#include <bits/stdc++.h>
using namespace std;
// Recursive + memoization
class Solution
{
public:
    int dp[1002][1002];
    // Function to find the length of longest common subsequence in two strings.
    int LCS(string s1, string s2, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;
        // choice diagram
        if (dp[n][m] != -1)
            return dp[n][m];
        if (s1[n - 1] == s2[m - 1])
            return dp[n][m] = 1 + LCS(s1, s2, n - 1, m - 1);
        else
        {
            return dp[n][m] = max(LCS(s1, s2, n - 1, m), LCS(s1, s2, n, m - 1));
        }

        return 0;
    }
    int lcs(int x, int y, string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));

        LCS(s1, s2, x, y);
        return dp[x][y];
    }
};

// ITERATIVE -> TOP-DOWN
int lcs(int m, int n, string s1, string s2)
{
    int dp[m + 1][n + 1];
    // base condn - > intilization
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0; // len is 0 when any string is empty
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
}