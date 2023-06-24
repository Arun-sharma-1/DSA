#include <bits/stdc++.h>
using namespace std;
// problem statement => cut rodes into part from three options a , b ,c such that sum of each part will be equal to n y
int maxx(int a, int b, int c)
{
    int ret = max(a, b);
    ret = max(ret, c);
    return ret;
}
int maxNoOfpeice(int n, int a, int b, int c)
{
    // n=23 , a =12 , b =9 ,c=11
    if (n == 0)
        return 0;
    if (n <= -1)
        return -1;
    int res = maxx(
        maxNoOfpeice(n - a, a, b, c),
        maxNoOfpeice(n - b, a, b, c),
        maxNoOfpeice(n - c, a, b, c)

    );
    if (res == -1)
        return -1;
    return ++res;
}
int main()
{
    cout << maxNoOfpeice(6, 3, 2, 1);
    return 0;
}

// ROD CUTTING
/*
Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: Consider 1-based indexing.
*/
int maxcuts(int price[], int index, int n)
{
    if (n <= 0 || index >= n)
        return 0;

    int notcut = maxcuts(price, index + 1, n);
    int cut = price[index] + maxcuts(price, index, n - (index + 1));

    return max(cut, notcut);
}
int cutRod(int price[], int n)
{
    
    return maxcuts(price, 0, n);
}