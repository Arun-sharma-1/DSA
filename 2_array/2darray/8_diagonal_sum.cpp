#include <bits/stdc++.h>
using namespace std;
int diagonalSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i] + mat[i][n - 1 - i];
    }
    //in odd matrix the middle column comes two time , so remove 
    if (n % 2 == 1)
    {
        sum -= mat[n / 2][n / 2];
    }
    return sum;
}
int main()
{
    return 0;
}