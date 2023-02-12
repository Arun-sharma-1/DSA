#include <bits/stdc++.h>
using namespace std;
int minOperations(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
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
    int lcs = dp[m][n];

    int deletion = s1.length() - lcs;
    int insertion = s2.length() - lcs;

    return deletion + insertion;
}
int main()
{
    /*
    Input: str1 = "heap", str2 = "pea"
    Output: 3
    Explanation: 2 deletions and 1 insertion
    p and h deleted from heap. Then, p is 
    inserted at the beginning One thing to 
    note, though p was required yet it was 
    removed/deleted first from its position 
    and then it is inserted to some other 
    position. Thus, p contributes one to the 
    deletion_count and one to the 
    insertion_count.
    */
}