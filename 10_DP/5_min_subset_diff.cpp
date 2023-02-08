#include <bits/stdc++.h>
using namespace std;
int minDifference(int arr[], int n)
{
    int sum = accumulate(arr, arr + n, 0);
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
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
    for (int i = 1; i < n + 1; i++)
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

    // last row h vo kaam ki h
    vector<int> v;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i])
        {
            v.push_back(i);
        }
    }
    // mere pass possible value h vector m
    int mini = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        mini = min(mini, abs(sum - 2 * v[i]));
    }
    return mini;
}
int main()
{
}