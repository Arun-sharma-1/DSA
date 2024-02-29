#include <bits/stdc++.h>
using namespace std;
void transpose(int a[3][3], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <i; j++)
        {
            // j<i coz we want to perform (0,1) and (1,0) only once
            swap(a[i][j], a[j][i]);
        }
    }
}
int main()
{
    int a[][3] = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3}};
    transpose(a, 3, 3);
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