#include <bits/stdc++.h>
using namespace std;
vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    // code here
    int top = 0;
    int left = 0;
    int bottom = r - 1;
    int right = c - 1;

    vector<int> res;
    while (top <= bottom && left <= right)
    {
        // left to right
        for (int i = left; i <= right; i++)
        {
            res.push_back(matrix[top][i]);
        }
        top++;

        // top to bottom
        for (int i = top; i <= bottom; i++)
        {
            res.push_back(matrix[i][right]);
        }
        right--;
        // right to left;
        if (bottom >= top)
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[bottom][i]);
            }
        bottom--;
        // bottom to top
        if (right >= left)
            for (int i = bottom; i >= top; i--)
            {
                res.push_back(matrix[i][left]);
            }
        left++;
    }
    return res;
}
int main()
{
    return 0;
}