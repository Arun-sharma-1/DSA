#include <bits/std++.h>
using namespace std;
//MINM NO OF INSRTION TO MAKE STRING PALINDROME == MIN NO OF DEL TO MAKE STRING PALINDROME
int minDeletions(string s1, int n)
{
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    int dp[n + 1][n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
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

    int lenLcs = dp[n][n];
    return n - lenLcs;
}
int main()
{
    /*
    Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.
Note: The order of characters should be maintained.*/
    return 0;
}