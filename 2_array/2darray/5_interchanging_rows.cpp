#include <bits/stdc++.h>
using namespace std;
void interchanging(int arr[][4], int n)
{
    // swap rows
    for (int row = 0; row < n / 2; row++)
    {
        for (int col = 0; col < n; col++)
        {
            swap(arr[row][col], arr[n - 1-row][col]);
        }
    }
}
void reverseColumn(int arr[][4],int n)
{
    for(int col=0; col<n; col++)
    {
        int sr=0;
        int er=n-1;
        while(er>sr)
        {
            swap(arr[sr][col],arr[er][col]);
            sr++;
            er--;
        }
    }
}
int main()
{
    int a[][4] = {
        {1, 1, 1,1},
        {2, 2, 2,2},
        {3, 3, 3,3},
        {4, 4, 4,4},
    };
    // interchanging(a, 4);
    reverseColumn(a,4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}