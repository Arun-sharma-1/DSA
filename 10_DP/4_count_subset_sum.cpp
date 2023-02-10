#include <bits/std++.h>
using namespace std;
int perfectSum(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j < sum + 1; j++)
    {
        dp[0][j] = 0;
    }

    int res = 0;
    int mod = 1e9 + 7;

    // j is starting from 0 coz if any 0 is present in input array it is giving wrong ans
    for (int i = 1; i < n + 1; i++)
    {
        //1 change is here 
        for (int j = 0; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                //1 change is here 
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod; //+ 
            }
            else
                dp[i][j] = dp[i - 1][j] % mod;
        }
    }
    return dp[n][sum] % mod;
}
int main()
{
}