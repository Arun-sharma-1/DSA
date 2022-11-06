#include <bits/stdc++.h>
using namespace std;
int summ(int arr[][2], int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            totalSum += arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            totalSum += arr[i][j];
        }
    }
    for (int col = 0; col < n; col++)
    {
        for (int row = 0; row < n; row++)
        {
            totalSum += arr[row][col];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            totalSum += arr[i][j];
        }
    }
    return totalSum;
}
int main()
{
    int a[2][2]={
        {1,1},
        {1,1}
    };
    cout<<summ(a,2);
    return 0;
}