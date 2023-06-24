#include <bits/stdc++.h>
using namespace std;
string shortestCommonSupersequence(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    int dp[m + 1][n + 1];
    // lcs
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string res;
    int i = m;
    int j = n;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            //agar common nhi h too bhi include krna h =>supersequence m 
            res.push_back(s1[i - 1]);
            i--;
        }
        else
        {
            res.push_back(s2[j - 1]);
            j--;
        }
    }

    while (i > 0)
    {
        res.push_back(s1[i - 1]);
        i--;
    }
    while (j > 0)
    {
        res.push_back(s2[j - 1]);
        j--;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    return 0;
}