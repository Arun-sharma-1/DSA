#include <bits/stdc++.h>
using namespace std;

int getMax1(int arr[], int n)
{
    int maxi = 0;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        maxi = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 1)
                maxi++;
            else
                break;
        }
        res = max(res, maxi); // res = 1 -> 2
    }
    return res;
}
int maxConsecutiveOne(int arr[], int n)
{
    int res = 0;
    int freq = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            freq++;
            res = max(res, freq); // 1,2,3,
        }
        else
        {
            freq = 0;
        }
    }
    return res;
}

int getMax2(int arr[], int n)
{
    int maxi = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 1)
            maxi = 0;
        else
        {
            maxi++;
            res = max(maxi, res);
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 0, 0, 4, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << getMax2(arr, size);
}