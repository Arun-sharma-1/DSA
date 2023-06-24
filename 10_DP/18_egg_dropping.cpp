#include <bits/stdc++.h>
using namespace std;
int DP[102][100001];
int solve(int e, int f)
{

    if (f == 1 || f == 0)
        return DP[e][f] = f;
    if (e == 1)
        return DP[e][f] = f;

    if (DP[e][f] != -1)
        return DP[e][f];

    int ans = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
        ans = min(ans, temp);
    }
    return DP[e][f] = ans;
}
int solve(int e, int f)
{
    if (f == 0 || f == 1)
        return f;
    else if (e == 1)
        return f;

    if (dp[e][f] != -1)
        return dp[e][f];
    int mini = INT_MAX;
    int low = 1;
    int high = f;
    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        int left = solve(e - 1, mid - 1);
        int right = solve(e, f - mid);
        long long temp = 1 + max(left, right);

        if (left < right)
        {                  // since right is more than left and we need more in worst case
            low = mid + 1; // so l=mid+1 to gain more temp for worst case : upward
        }
        else // left > right so we will go downward
        {
            high = mid - 1;
        }
        if (temp < mini)
            mini = temp;
    }

    return dp[e][f] = mini;
}
int superEggDrop(int k, int n)
{
    memset(DP, -1, sizeof(DP));
    int result = solve(k, n);
    return result;
}
int main()
{

    return 0;
}