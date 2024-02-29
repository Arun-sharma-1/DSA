#include <bits/stdc++.h>
using namespace std;
bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    // code here
    int i = 0;
    int j = m - 1;

    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (matrix[i][j] == x)
            return true;

        else if (matrix[i][j] > x)
            j--;
        else
            i++;
    }
    return false;
}
int main()
{
    return 0;
}