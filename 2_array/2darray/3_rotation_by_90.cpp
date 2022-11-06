#include <bits/stdc++.h>
using namespace std;
void rotation(int a[][3], int m, int n)
{
    // 1.row reverse
    // for (int i = 0; i < m; i++)
    // {
    //     int start_col = 0;
    //     int end_col = n - 1;
    //     while (end_col > start_col)
    //     {
    //         swap(a[i][start_col], a[i][end_col]);
    //         start_col++;
    //         end_col--;
    //     }
    // }

    //reverse using stl
    for(int i=0; i<n; i++)
    {
        reverse(a[i],a[i]+n);
    }
    
    // 2.transpose
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(a[i][j], a[j][i]);
        }
    }
}
int main()
{
    int a[][3] = {
        {1, 4, 1},
        {2, 8, 4},
        {3, 9, 5}};
    rotation(a, 3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}