#include <bits/stdc++.h>
using namespace std;
void visitCurrIsland(vector<vector<char>> &grid, int i, int j, int r, int c)
{
    if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] != '1') // Boundary case for matrix
        return;

    // marks visited
    grid[i][j] = '0';

    visitCurrIsland(grid, i + 1, j, r, c);
    visitCurrIsland(grid, i - 1, j, r, c);
    visitCurrIsland(grid, i, j + 1, r, c);
    visitCurrIsland(grid, i, j - 1, r, c);
}
int numIslands(vector<vector<char>> &grid)
{

    int rows = grid.size();
    int col = grid[0].size();

    if (rows == 0)
        return 0;
    int islands = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '1')
            {
                visitCurrIsland(grid, i, j, rows, col);
                islands++;
            }
        }
    }
    return islands;
}
int main()
{
     
    vector<vector<char>> grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]

    ];
}